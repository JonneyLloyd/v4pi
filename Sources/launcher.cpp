#include "launcher.h"




int Launcher::cam_test()
{
    factory = new V4l2Factory();
    jpeg_test = factory->init();
    return jpeg_test->run();
}

int Launcher::alpr_test()
{
    return alprJpeg.run();
}
