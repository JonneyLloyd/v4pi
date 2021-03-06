#include "v4l2_factory.h"


V4l2Interface * V4l2Factory::init(){
  return V4l2Factory::init("/dev/video0", 640, 480);
}

V4l2Interface * V4l2Factory::init(std::string address, int width, int height){
  return new V4l2Handler(address, width, height);

}

V4l2Interface * V4l2Factory::init(std::string address, int width, int height, DataTypes::Enum data_type){
  return new V4l2Handler(address, width, height, data_type);

}

V4l2Interface * V4l2Factory::init(std::string address, int width, int height, DataTypes::Enum data_type, int framerate){
  return new V4l2Handler(address, width, height, data_type, framerate);

}
