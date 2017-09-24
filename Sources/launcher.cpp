#include "launcher.h"




int Launcher::cam_test()
{
    return cameraGrab.run();
}

int Launcher::alpr_test()
{
    return alprJpeg.run();
}
