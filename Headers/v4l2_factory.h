#ifndef V4L2_FACTORY
#define V4L2_FACTORY

#include "v4l2_handler.h"


class V4l2Factory{
public:
  V4l2Interface * init();
  V4l2Interface * init(std::string address, int width, int height);
};



#endif // V4L2_FACTORY
