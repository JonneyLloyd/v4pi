#ifndef V4L2_HANDLER
#define V4L2_HANDLER

#include "v4l2_interface.h"





class V4l2Handler : public V4l2Interface
{
public:
  V4l2Handler(std::string address, int width, int height);
  void set_address(std::string address);
  std::string get_address();
  void set_width(int width);
  int get_width();
  void set_height(int height);
  int get_height();
  void set_save_location(std::string save_location);
  std::string get_save_location();
  int run();
  void open_device();
  void get_device_cap(int fd);
  void set_format();
  void buffer_setup();
  struct v4l2_buffer get_buffer();
  void queue_buffer();
  void dequeue_buffer();
  void activate_streaming();
  void deactivate_streaming();
  void save_jpeg(std::string save_location);
  void init();

private:
  std::string address;
  std::string save_location;
  int width;
  int height;
  int fd;
  struct v4l2_capability cap;
  struct v4l2_format format;
  struct v4l2_requestbuffers bufrequest;
  struct v4l2_buffer bufferinfo;
  void* buffer_start;
  int buf_type;



};

#endif
