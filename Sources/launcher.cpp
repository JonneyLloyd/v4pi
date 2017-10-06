#include "launcher.h"

int Launcher::cam_test()
{
    factory = new V4l2Factory();
    jpeg_test = factory->init("/dev/video0", 800, 600);
    jpeg_test->init();
    jpeg_test->queue_buffer();
    jpeg_test->activate_streaming();
    jpeg_test->dequeue_buffer();
    jpeg_test->deactivate_streaming();
    jpeg_test->save_jpeg("/home/pi/myimage.jpeg");
    return 1;

}

int Launcher::alpr_test()
{
    return alprJpeg.run();
}
