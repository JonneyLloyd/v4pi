#include "launcher_cv.h"
#include <vector>
#include <chrono>

//sudo modprobe bcm2835-v4l2

int LauncherCV::cam_test()
{
    cv::VideoCapture cap(0);
    if ( !cap.isOpened() )
    {
         std::cout << "Cannot open the web cam" << std::endl;
         return -1;
    }
    compression_params.push_back(cv::IMWRITE_JPEG_QUALITY );
    cv::Mat frame;
    std::cout << "Snapshot test "  << std::endl;
    cap.set(CV_CAP_PROP_FRAME_WIDTH, width);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, height);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end;

    cap >> frame; // get a new frame from camera
    imwrite("imageCV.jpg", frame, compression_params); //sanity check

    end= std::chrono::steady_clock::now();
    std::cout << "Snapshot test, pure CV = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;


    begin = std::chrono::steady_clock::now();
    end= std::chrono::steady_clock::now();
    int time_diff = 0, count = 0;
    unsigned char * test_frame;
    while (time_diff < 1000){
      begin = std::chrono::steady_clock::now();
      cap >> frame; // get a new frame from camera
      count ++;
      end= std::chrono::steady_clock::now();
      time_diff += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    }
    std::cout << "Framerate test " <<  count << std::endl;



    int x = 0;

    while(x < 10){
    x++;
    begin = std::chrono::steady_clock::now();
    std::cout << "Loop start" << std::endl;
    cap >> frame; // get a new frame from camera

    alprJpeg.run(frame);
    end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
  }
    std::cout << "Exiting program" << std::endl;
    return 1;

}
