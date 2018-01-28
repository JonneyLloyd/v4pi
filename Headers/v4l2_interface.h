#ifndef V4L2_INTERFACE
#define V4L2_INTERFACE

#include <string.h>
#include <string>
#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class V4l2Interface{
public:
  virtual void set_address(std::string address) = 0;
  virtual std::string get_address() = 0;
  virtual void set_width(int width) = 0;
  virtual int get_width() = 0;
  virtual void set_height(int height) = 0;
  virtual int get_height() = 0;
  virtual void open_device() = 0;
  virtual void get_device_cap(int fd) = 0;
  virtual void set_format() = 0;
  virtual void buffer_setup() = 0;
  virtual unsigned char *  get_buffer() = 0;
  virtual cv::Mat get_cv_mat() = 0;
  virtual void save_jpeg(std::string save_location) = 0;
  virtual void init() = 0;
  virtual void teardown() = 0;
  virtual void set_framerate() = 0;
};


#endif // V4L2_INTERFACE
