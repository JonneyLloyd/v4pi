#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "v4l2_factory.h"
#include "v4l2_handler.h"
#include "alpr_jpeg.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class Launcher
{
public:
    int cam_test();

private:
    V4l2Factory* factory;
    V4l2Interface* jpeg_test;
    AlprJpeg alprJpeg;
    cv::Mat frame;
    std::vector<int> compression_params;
};


#endif // LAUNCHER_H
