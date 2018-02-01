#include "launcher.h"

#include <vector>
#include <chrono>

//sudo modprobe bcm2835-v4l2
//sudo sshfs -o allow_other,default_permissions pi@192.168.1.101:/home/pi/FYP/ /mnt/raspberry/


int Launcher::cam_test()
{
    factory = new V4l2Factory();
    data_type = DataTypes::Enum::RGB;
    address = "/dev/video0";
    jpeg_test = factory->init(address, width, height, data_type, framerate);
    jpeg_test->init();
    cv::Mat test_pic;

    switch(data_type) {
        case DataTypes::Enum::YU12  :
        test_pic = cv::Mat(height, width, CV_8UC1, jpeg_test->get_buffer());
        break;

        case DataTypes::Enum::MJPEG  :
        test_pic = cv::imdecode(cv::Mat(height,width, CV_8UC3, jpeg_test->get_buffer()),1);
        break;

        case DataTypes::Enum::RGB  :
        test_pic = cv::Mat(height,width, CV_8UC3, jpeg_test->get_buffer());
        cv::cvtColor(test_pic, test_pic, cv::COLOR_RGB2BGR);
        break;

        case DataTypes::Enum::BGR  :
        test_pic = cv::Mat(height, width, CV_8UC3, jpeg_test->get_buffer());
        break;

        default :
        std::cout << "Unsupported format!" << std::endl;
  }

    cv::imwrite("test.bmp", test_pic);  //sanity check

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    int time_diff = 0, count = 0;
    unsigned char * test_frame;
    begin = std::chrono::steady_clock::now();
    while (time_diff <= 1000){

      test_frame = jpeg_test->get_buffer();
      count ++;
      end= std::chrono::steady_clock::now();
      time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    }
    std::cout << "Framerate test " <<  count << " FPS" << std::endl;


    int x = 0;
    std::cout << "Raw data " << std::endl;
    while(x < 5){
      x++;
      begin = std::chrono::steady_clock::now();
      std::cout << "Loop start" << std::endl;

      switch(data_type) {
          case DataTypes::Enum::YU12  :
          alprJpeg.run(jpeg_test->get_buffer(),  1, width, height);
          break;

          case DataTypes::Enum::MJPEG  :
          frame = (cv::imdecode(cv::Mat(height,width, CV_8UC3, jpeg_test->get_buffer()),1));
          alprJpeg.run(frame);
          break;

          case DataTypes::Enum::RGB  :
          frame = cv::Mat(height,width, CV_8UC3, jpeg_test->get_buffer());
          cv::cvtColor(frame, frame, cv::COLOR_RGB2BGR);
          alprJpeg.run(frame);
          break;

          case DataTypes::Enum::BGR  :
          alprJpeg.run(jpeg_test->get_buffer(),  3, width, height);
          break;

          default :
          std::cout << "Unsupported format!" << std::endl;
    }

      end= std::chrono::steady_clock::now();
      std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
    }

    x = 0;
    std::cout << "OpenCV conversion " << std::endl;
    while(x < 5){
      x++;
      begin = std::chrono::steady_clock::now();
      std::cout << "Loop start" << std::endl;
      frame = jpeg_test->get_cv_mat();
      alprJpeg.run(frame);
      end= std::chrono::steady_clock::now();
      std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
    }

    jpeg_test->teardown();
    std::cout << "Exiting program" << std::endl;
    return 1;

}
