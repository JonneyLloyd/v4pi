#include "v4l2_handler.h"

V4l2Handler::V4l2Handler(std::string address, int width, int height)
  : address{address},
    width{width},
    height{height},
    data_type{DataTypes::Enum::YU12},
    framerate{30}
    {
      int nThreads;
      nThreads = omp_get_max_threads();
      omp_set_num_threads(nThreads);
    }

V4l2Handler::V4l2Handler(std::string address, int width, int height, DataTypes::Enum data_type)
  : address{address},
    width{width},
    height{height},
    data_type{data_type},
    framerate{30}
    {
      int nThreads;
      nThreads = omp_get_max_threads();
      omp_set_num_threads(nThreads);
    }

V4l2Handler::V4l2Handler(std::string address, int width, int height, DataTypes::Enum data_type, int framerate)
  : address{address},
    width{width},
    height{height},
    data_type{data_type},
    framerate{framerate}
    {
      int nThreads;
      nThreads = omp_get_max_threads();
      omp_set_num_threads(nThreads);
    }

void V4l2Handler::set_address(std::string address){
  this->address = address;
}

std::string V4l2Handler::get_address(){
  return this->address;
}

void V4l2Handler::set_framerate(int framerate){
  this->framerate = framerate;
}

int V4l2Handler::get_framerate(){
  return this->framerate;
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
  struct v4l2_capability cap;
  CLEAR(cap);

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
  struct v4l2_format format;
  CLEAR(format);
  format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  switch(data_type) {
      case DataTypes::Enum::YU12  :
      std::cout << "YU12 format selected"  << std::endl;
      format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUV420;
      break;

      case DataTypes::Enum::MJPEG  :
      std::cout << "MJPEG format selected"  << std::endl;
      format.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
      break;

      case DataTypes::Enum::RGB  :
      std::cout << "RGB format selected"  << std::endl;
      format.fmt.pix.pixelformat = V4L2_PIX_FMT_RGB24;
      break;

      case DataTypes::Enum::BGR  :
      std::cout << "BGR format selected "  << std::endl;
      format.fmt.pix.pixelformat = V4L2_PIX_FMT_BGR24;
      break;



      default :
      std::cout << "Unknown format! YU12 Formated selected "  << std::endl;
      format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUV420;
}

  format.fmt.pix.width = get_width();
  format.fmt.pix.height = get_height();

  if(ioctl(fd, VIDIOC_S_FMT, &format) < 0){
      perror("VIDIOC_S_FMT");
      exit(1);
  }
}

void V4l2Handler::set_v4l2_framerate()
{

    struct v4l2_streamparm parm;
    CLEAR(parm);

    parm.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    //reversed due to driver issue
    parm.parm.capture.timeperframe.numerator = 1;
    parm.parm.capture.timeperframe.denominator = get_framerate();

    if(ioctl(fd, VIDIOC_S_PARM, &parm) < 0){
        perror("VIDIOC_S_FMT");
        exit(1);
    }
}

void V4l2Handler::buffer_setup(){
  struct v4l2_buffer bufferinfo;
  struct v4l2_requestbuffers bufrequest;
  CLEAR(bufferinfo);
  CLEAR(bufrequest);
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
                  mmap(NULL,
                        bufferinfo.length,
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED,
                        fd,
                        bufferinfo.m.offset);

            if (MAP_FAILED == buffers[n_buffers].data)
                  perror("mmap");
}
std::cout <<  "buffer setup complete\n";
}

unsigned char * V4l2Handler::get_buffer(){
  if (read_frame())
    return output;
  else
    return NULL;
}

cv::Mat V4l2Handler::get_cv_mat(){
  switch(data_type) {
      case DataTypes::Enum::YU12  :
      mat = cv::Mat(get_height(), get_width(), CV_8UC1, get_buffer());
      break;

      case DataTypes::Enum::MJPEG  :
      mat = cv::imdecode(cv::Mat(get_height(), get_width(), CV_8UC3, get_buffer()),1);

      break;

      case DataTypes::Enum::RGB  :
      mat = cv::Mat(get_height(), get_width(), CV_8UC3, get_buffer());
      cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
      break;

      case DataTypes::Enum::BGR  :
      mat = cv::Mat(get_height(), get_width(), CV_8UC3, get_buffer());
      break;

      default :
      mat = cv::Mat(get_height(), get_width(), CV_8UC1, get_buffer());
}
  return mat;
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
                /* ignore EIO. */

                /* fall through */

            default:
                perror("VIDIOC_DQBUF");
        }
    }

    assert(buf.index < n_buffers);
    output= (unsigned char *)buffers[buf.index].data;

    if (-1 == ioctl(fd, VIDIOC_QBUF, &buf))
        perror("VIDIOC_QBUF");

    return true;
}

bool V4l2Handler::snapshot()
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
                /* ignore EIO. */
            default:
                perror("VIDIOC_DQBUF");
        }
    }

    fout = fopen("out.ppm", "w");
    if (!fout) {
          perror("Cannot open image");
          exit(EXIT_FAILURE);
    }
    fprintf(fout, "P6\n%d %d 255\n",
          get_width(), get_height());
    fwrite(buffers[buf.index].data, buf.bytesused, 1, fout);
    fclose(fout);

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

bool V4l2Handler::save_jpeg(std::string save_location)
{
  int jpgfile;
  if((jpgfile = open(save_location.c_str(), O_WRONLY | O_CREAT, 0660)) < 0){
      perror("open");
      exit(1);
  }
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
                /* ignore EIO. */
            default:
                perror("VIDIOC_DQBUF");
        }
    }

    write(jpgfile, buffers[buf.index].data, buf.bytesused);
    close(jpgfile);

    if (-1 == ioctl(fd, VIDIOC_QBUF, &buf))
        perror("VIDIOC_QBUF");

    return true;
}

void V4l2Handler::init(){
  open_device();
  get_device_cap(fd);
  set_v4l2_framerate();
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
  free(buffers);
}

void V4l2Handler::sighthound(char const* key){
  struct curl_slist *headerlist=NULL;
  FILE *fd2 = fopen("out.jpg", "rb");
  struct stat file_info;
  fstat(fileno(fd2), &file_info);
  CURL *curl;
  CURLcode res;
  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */
    std::string temp("X-Access-Token: ");
    temp.append(key);
    headerlist = curl_slist_append( headerlist, temp.c_str());
    headerlist = curl_slist_append( headerlist, "Content-Type: application/octet-stream");
    curl_easy_setopt(curl, CURLOPT_HEADER, true);
    curl_easy_setopt(curl, CURLOPT_URL, "https://dev.sighthoundapi.com/v1/recognition?objectType=vehicle");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_READDATA, fd2);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)file_info.st_size);


    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);

}
curl_global_cleanup();
}

void V4l2Handler::sighthound_face(char const* key){
  struct curl_slist *headerlist=NULL;
  FILE *fd2 = fopen("out.jpg", "rb");
  struct stat file_info;
  fstat(fileno(fd2), &file_info);
  CURL *curl;
  CURLcode res;
  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */
    std::string temp("X-Access-Token: ");
    temp.append(key);
    headerlist = curl_slist_append( headerlist, temp.c_str());
    headerlist = curl_slist_append( headerlist, "Content-Type: application/octet-stream");
    curl_easy_setopt(curl, CURLOPT_HEADER, true);
    curl_easy_setopt(curl, CURLOPT_URL, "https://dev.sighthoundapi.com/v1/image/imageId?objectId=id2&objectType=person&train=manual");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_READDATA, fd2);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)file_info.st_size);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);


    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);

}
curl_global_cleanup();
}
