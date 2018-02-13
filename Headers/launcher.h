#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "v4l2_factory.h"
#include "v4l2_handler.h"
#include "alpr_jpeg.h"
#include "data_types_enum.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <chrono>
#include <vector>

class Launcher
{
public:
    int cam_test();
    void snapshot_test();
    void jpeg_snapshot_test();

private:
    int width = 640;
    int height = 480;
    int framerate = 60;
    V4l2Factory* factory;
    V4l2Interface* jpeg_test;
    AlprJpeg alprJpeg;
    cv::Mat frame;
    std::vector<int> compression_params;
    DataTypes::Enum data_type;
    std::string address;
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
};


#endif // LAUNCHER_H
