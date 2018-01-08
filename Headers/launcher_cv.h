#ifndef LAUNCHERCV_H
#define LAUNCHERCV_H


#include "alpr_jpeg.h"
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class LauncherCV
{
public:
    int cam_test();

private:

    AlprJpeg alprJpeg;
    cv::Mat frame;
    std::vector<int> compression_params;
};


#endif // LAUNCHERCV_H
