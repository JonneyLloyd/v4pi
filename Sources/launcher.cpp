#include "launcher.h"
#include <vector>

int Launcher::cam_test()
{
    factory = new V4l2Factory();
    jpeg_test = factory->init("/dev/video0", 800, 600);
    jpeg_test->init();
    jpeg_test->queue_buffer();
    jpeg_test->activate_streaming();
    jpeg_test->dequeue_buffer();
    jpeg_test->deactivate_streaming();

    frame = cv::imdecode(cv::Mat(600,800, CV_8UC3, jpeg_test->get_buffer()),1);
    compression_params.push_back(cv::IMWRITE_JPEG_QUALITY );
    //imwrite("image.jpg", frame, compression_params);
    alprJpeg.run(frame);
/*
    jpeg_test->queue_buffer();
    jpeg_test->dequeue_buffer();
    frame = cv::imdecode(cv::Mat(600,800, CV_8UC3, jpeg_test->get_buffer()),1);
    //imwrite("image.jpg", frame, compression_params);
    alprJpeg.run(frame);
*/
    jpeg_test->teardown();
    return 1;

}
