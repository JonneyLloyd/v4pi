#include "launcher.h"
#include <vector>
#include <chrono>

int Launcher::cam_test()
{
    factory = new V4l2Factory();
    jpeg_test = factory->init("/dev/video0", 800, 600);
    compression_params.push_back(cv::IMWRITE_JPEG_QUALITY );
    jpeg_test->init();
    jpeg_test->queue_buffer();
    jpeg_test->activate_streaming();
    jpeg_test->dequeue_buffer();
    //jpeg_test->deactivate_streaming();

    frame = cv::imdecode(cv::Mat(600,800, CV_8UC3, jpeg_test->get_buffer()),1);
    compression_params.push_back(cv::IMWRITE_JPEG_QUALITY );
    imwrite("image.jpg", frame, compression_params);
    alprJpeg.run(frame);
/*
    jpeg_test->queue_buffer();
    jpeg_test->dequeue_buffer();
    frame = cv::imdecode(cv::Mat(600,800, CV_8UC3, jpeg_test->get_buffer()),1);
    //imwrite("image.jpg", frame, compression_params);
    alprJpeg.run(frame);
*/
    int x = 0;


    while(x < 10){
      x++;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::cout << "Loop start" << std::endl;
    jpeg_test->queue_buffer();
    //jpeg_test->activate_streaming();
    jpeg_test->dequeue_buffer();
  //  jpeg_test->deactivate_streaming();

    frame = cv::imdecode(cv::Mat(600,800, CV_8UC3, jpeg_test->get_buffer()),1);

    //imwrite("image.jpg", frame, compression_params);
    alprJpeg.run(frame);
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
  }
    jpeg_test->deactivate_streaming();
    jpeg_test->teardown();
    std::cout << "Exiting program" << std::endl;
    return 1;

}
