#ifndef ALPR_JPEG_H
#define ALPR_JPEG_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <alpr.h>

class AlprJpeg{
public:
    int run(cv::Mat &frame);
    int run(unsigned char * frame,  int bytesPerPixel, int imgWidth, int imgHeight);

};

#endif // ALPR_JPEG_H
