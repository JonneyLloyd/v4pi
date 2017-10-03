#ifndef V4L2_JPEG
#define V4L2_JPEG

#include "v4l2_factory.h"





class V4l2_Jpeg : public V4l2_Factory
{
public:
  V4l2_Jpeg(std::string address, int width, int height);
  void set_address(std::string address);
  std::string get_address();
  void set_width(int width);
  int get_width();
  void set_height(int height);
  int get_height();
  int run();

private:
  std::string address;
  int width;
  int height;


};

#endif
