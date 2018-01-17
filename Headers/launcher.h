#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "v4l2_factory.h"
#include "v4l2_handler.h"
#include "alpr_jpeg.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class Launcher
{
public:
    int cam_test();
    int width = 640;
    int height = 480;

private:
    V4l2Factory* factory;
    V4l2Interface* jpeg_test;
    AlprJpeg alprJpeg;
    cv::Mat frame;
    std::vector<int> compression_params;
};


#endif // LAUNCHER_H
