#ifndef ALPR_JPEG_H
#define ALPR_JPEG_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <alpr.h>

class AlprJpeg{
public:
    int run(cv::Mat &frame);

};

#endif // ALPR_JPEG_H
