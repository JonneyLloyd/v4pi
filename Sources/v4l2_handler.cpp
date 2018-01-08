#include "v4l2_handler.h"

V4l2Handler::V4l2Handler(std::string address, int width, int height)
  : address{address},
    width{width},
    height{height}
    {
    }

void V4l2Handler::set_address(std::string address){
  this->address = address;
}

std::string V4l2Handler::get_address(){
  return this->address;
}

void V4l2Handler::set_width(int width){
  this->width = width;
}

int V4l2Handler::get_width(){
  return this->width;
}

void V4l2Handler::set_height(int height){
  this->height = height;
}

int V4l2Handler::get_height(){
  return this->height;
}

void V4l2Handler::set_save_location(std::string save_location){
  this->save_location = save_location;
}

std::string V4l2Handler::get_save_location(){
  return this->save_location;
}



void V4l2Handler::open_device(){
  fd = -1;
  if((fd = open(get_address().c_str(), O_RDWR)) < 0){
      perror("open");
      exit(1);
  }
}

void V4l2Handler::get_device_cap(int fd){

  if(ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0){
      perror("VIDIOC_QUERYCAP");
      exit(1);
  }
  if(!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)){
      fprintf(stderr, "The device does not handle single-planar video capture.\n");
      exit(1);
  }
}

void V4l2Handler::set_format(){
  format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  format.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
  format.fmt.pix.width = get_width();
  format.fmt.pix.height = get_height();

  if(ioctl(fd, VIDIOC_S_FMT, &format) < 0){
      perror("VIDIOC_S_FMT");
      exit(1);
  }
}

void V4l2Handler::buffer_setup(){
  bufrequest.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  bufrequest.memory = V4L2_MEMORY_MMAP;
  bufrequest.count = 3;
  if(ioctl(fd, VIDIOC_REQBUFS, &bufrequest) < 0){
      perror("VIDIOC_REQBUFS");
      exit(1);
  }

  buffers = (buffer*) calloc(bufrequest.count, sizeof(*buffers));
  if (!buffers) {
            perror("Out of memory");
  }
  for (n_buffers = 0; n_buffers < bufrequest.count; ++n_buffers) {
            struct v4l2_buffer buf;

            CLEAR(buf);

            bufferinfo.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
            bufferinfo.memory      = V4L2_MEMORY_MMAP;
            bufferinfo.index       = n_buffers;

            if (-1 == ioctl(fd, VIDIOC_QUERYBUF, &bufferinfo))
                  perror("VIDIOC_QUERYBUF");

            buffers[n_buffers].size = bufferinfo.length;
            buffers[n_buffers].data =
                  mmap(NULL /* start anywhere */,
                        bufferinfo.length,
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED,
                        fd, bufferinfo.m.offset);

            if (MAP_FAILED == buffers[n_buffers].data)
                  perror("mmap");
}
std::cout <<  "buffer setup complete";
}




/*
  memset(&bufferinfo, 0, sizeof(bufferinfo));

  bufferinfo.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  bufferinfo.memory = V4L2_MEMORY_MMAP;
  bufferinfo.index = 0;

  if(ioctl(fd, VIDIOC_QUERYBUF, &bufferinfo) < 0){
      perror("VIDIOC_QUERYBUF");
      exit(1);
  }

  buffer_start = mmap(
      NULL,
      bufferinfo.length,
      PROT_READ | PROT_WRITE,
      MAP_SHARED,
      fd,
      bufferinfo.m.offset
  );

  if(buffer_start == MAP_FAILED){
      perror("mmap");
      exit(1);
  }
  memset(buffer_start, 0, bufferinfo.length);
}*/

void* V4l2Handler::get_buffer(){
  read_frame();
  return output;

}

void V4l2Handler::queue_buffer(){
  // Put the buffer in the incoming queue.
  if(ioctl(fd, VIDIOC_QBUF, &bufferinfo) < 0){
      perror("VIDIOC_QBUF");
      exit(1);
  }
}

void V4l2Handler::dequeue_buffer(){
  // Dequeue the buffer.
  if(ioctl(fd, VIDIOC_DQBUF, &bufferinfo) < 0){
      perror("VIDIOC_DQBUF");
      exit(1);
  }

  bufferinfo.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  bufferinfo.memory = V4L2_MEMORY_MMAP;
  /* Set the index if using several buffers */
}

void V4l2Handler::activate_streaming(){
  // Activate streaming
  buf_type = bufferinfo.type;
  if(ioctl(fd, VIDIOC_STREAMON, &buf_type) < 0){
      perror("VIDIOC_STREAMON");
      exit(1);
  }
}




bool V4l2Handler::read_frame()
{

    struct v4l2_buffer buf;
    int i;

    CLEAR(buf);

    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;

    if (-1 == ioctl(fd, VIDIOC_DQBUF, &buf)) {
        switch (errno) {
            case EAGAIN:
                return false;

            case EIO:
                /* Could ignore EIO, see spec. */

                /* fall through */

            default:
                perror("VIDIOC_DQBUF");
        }
    }

    assert(buf.index < n_buffers);
    output= buffers[buf.index].data;
/*
    v4lconvert_yuyv_to_rgb24((unsigned char *) buffers[buf.index].data,
                             rgb_frame.data,
                             xres,
                             yres,
                             stride);
*/
    if (-1 == ioctl(fd, VIDIOC_QBUF, &buf))
        perror("VIDIOC_QBUF");

    return true;
}

void V4l2Handler::start_capturing()
{
    unsigned int i;
    enum v4l2_buf_type type;

    for (i = 0; i < n_buffers; ++i) {
        struct v4l2_buffer buf;

        CLEAR(buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = i;

        if (-1 == ioctl(fd, VIDIOC_QBUF, &buf))
            perror("VIDIOC_QBUF");
    }
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (-1 == ioctl(fd, VIDIOC_STREAMON, &type))
        perror("VIDIOC_STREAMON");
}



void V4l2Handler::deactivate_streaming(){
  // Deactivate streaming
  if(ioctl(fd, VIDIOC_STREAMOFF, &buf_type) < 0){
      perror("VIDIOC_STREAMOFF");
      exit(1);
  }
}

void V4l2Handler::save_jpeg(std::string save_location){
  int jpgfile;
  if((jpgfile = open(save_location.c_str(), O_WRONLY | O_CREAT, 0660)) < 0){
      perror("open");
      exit(1);
  }

  write(jpgfile, buffer_start, bufferinfo.length);
  close(jpgfile);

}

void V4l2Handler::init(){
  open_device();
  get_device_cap(fd);
  set_format();
  buffer_setup();
  start_capturing();
}

void V4l2Handler::teardown(){
  close(fd);
  int i;

 for (i = 0; i < n_buffers; ++i)
     if (-1 == munmap(buffers[i].data, buffers[i].size))
         perror("munmap");
         free (output);
         free(buffers);
}
