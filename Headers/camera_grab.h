#ifndef CAMERA_GRAB_H
#define CAMERA_GRAB_H

#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

class CameraGrab{
public:
    int run();

};



#endif // CAMERA_GRAB_H
