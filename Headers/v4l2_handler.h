#ifndef V4L2_HANDLER
#define V4L2_HANDLER

#define CLEAR(x) memset(&(x), 0, sizeof(x))

#include "v4l2_interface.h"
#include <memory> // unique_ptr
#include <assert.h>
#include <iostream>


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
  void open_device();
  void get_device_cap(int fd);
  void set_format();
  void buffer_setup();
  unsigned char * get_buffer();
  void queue_buffer();
  void dequeue_buffer();
  void activate_streaming();
  void deactivate_streaming();
  void save_jpeg(std::string save_location);
  void init();
  void start_capturing();
  void teardown();
  bool read_frame();

private:
  struct buffer {
      void   *data;
      size_t  size;
};
  std::string address;
  std::string save_location;
  int width;
  int height;
  int fd;
  struct v4l2_capability cap;
  struct v4l2_format format;
  struct v4l2_requestbuffers bufrequest;
  struct v4l2_buffer bufferinfo;
  struct buffer * buffers;
  int n_buffers;
  void* buffer_start;
  unsigned char * output;
  int buf_type;

};

#endif
