#include "launcher.h"
#include <vector>
#include <chrono>

//sudo modprobe bcm2835-v4l2
//sudo sshfs -o allow_other,default_permissions pi@192.168.1.7:/home/pi/FYP/ /mnt/raspberry/


int Launcher::cam_test()
{
    factory = new V4l2Factory();
    jpeg_test = factory->init("/dev/video0", width, height);
    jpeg_test->init();


    cv::Mat picYV12 = cv::Mat(height * 3/2, width, CV_8UC1, jpeg_test->get_buffer());
    //cv::Mat picBGR;
    //cv::cvtColor(picYV12, picBGR, cv::COLOR_YUV2BGR_YV12);
    cv::imwrite("test.bmp", picYV12);  //sanity check

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    int time_diff = 0, count = 0;
    unsigned char * test_frame;
    while (time_diff < 1000){
      begin = std::chrono::steady_clock::now();
      test_frame = jpeg_test->get_buffer();
      count ++;
      end= std::chrono::steady_clock::now();
      time_diff += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    }
    std::cout << "Framerate test " <<  count << " FPS" << std::endl;


    int x = 0;
    while(x < 10){
      x++;
      begin = std::chrono::steady_clock::now();
      std::cout << "Loop start" << std::endl;

      alprJpeg.run(jpeg_test->get_buffer(),  1, width, height);
      end= std::chrono::steady_clock::now();
      std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
    }

    jpeg_test->teardown();
    std::cout << "Exiting program" << std::endl;
    return 1;

}
