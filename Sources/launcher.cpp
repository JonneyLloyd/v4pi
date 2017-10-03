#include "launcher.h"




int Launcher::cam_test()
{
    jpeg_test = new V4l2_Jpeg("/dev/video0", 800, 600);
    return jpeg_test->run();
}

int Launcher::alpr_test()
{
    return alprJpeg.run();
}
