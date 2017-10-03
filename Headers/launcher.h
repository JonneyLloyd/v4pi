#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "v4l2_jpeg.h"
#include "alpr_jpeg.h"

class Launcher
{
public:
    int cam_test();
    int alpr_test();

private:
    V4l2_Jpeg * jpeg_test;
    AlprJpeg alprJpeg;
};


#endif // LAUNCHER_H
