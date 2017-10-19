#include "v4l2_factory.h"



V4l2Interface * V4l2Factory::init(){
  return V4l2Factory::init("/dev/video0", 800, 600);
}

V4l2Interface * V4l2Factory::init(std::string address, int width, int height){
  return new V4l2Handler(address, width, height);
}