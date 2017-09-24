#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "camera_grab.h"
#include "alpr_jpeg.h"

class Launcher
{
public:
    int cam_test();
    int alpr_test();

private:
    CameraGrab cameraGrab;
    AlprJpeg alprJpeg;
};


#endif // LAUNCHER_H
