#include "launcher.h"

// Below command is needed to launch Pi Camera driver
//sudo modprobe bcm2835-v4l2


/*
* Snapshot function to save ppm image
*/
void Launcher::snapshot_test()
{
  std::cout << std::endl << "Snapshot test" << std::endl;

  begin = std::chrono::steady_clock::now();
  jpeg_test->snapshot();
  end= std::chrono::steady_clock::now();
  std::cout << "Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;

  std::cout << std::endl << "CV Snapshot test" << std::endl;
  begin = std::chrono::steady_clock::now();
  frame = jpeg_test->get_cv_mat();
  imwrite("imageCV.ppm", frame);
  end= std::chrono::steady_clock::now();
  std::cout << "CV Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;

}

/*
* Snapshot function when MJPEG format has been used
*/
void Launcher::jpeg_snapshot_test()
{
  std::cout << std::endl << "Snapshot test" << std::endl;
  begin = std::chrono::steady_clock::now();

  jpeg_test->save_jpeg("out.jpg");
  end = std::chrono::steady_clock::now();
  std::cout << "Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;

  std::cout << std::endl << "CV Snapshot test" << std::endl;
  begin = std::chrono::steady_clock::now();
  frame = jpeg_test->get_cv_mat();
  imwrite("imageCV.jpg", frame);
  end = std::chrono::steady_clock::now();
  std::cout << "CV Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;
}

/*
* Saves an avi video at 24 FPS
*/
void Launcher::video_test()
{
  std::cout << std::endl << "Video test" << std::endl;
  cv::VideoWriter video("out.avi",CV_FOURCC('D','I','V','X'),60, cv::Size(width, height),true);
  int count = 0;
  while (count < 200){
    frame = jpeg_test->get_cv_mat();
    video.write(frame);

    count++;
  }
  std::cout << std::endl << "Video test complete" << std::endl;
}



int Launcher::cam_test()
{
    factory = new V4l2Factory();
    data_type = DataTypes::Enum::BGR;
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

    //Compare snapshot function
    if (data_type  == DataTypes::Enum::RGB || data_type  == DataTypes::Enum::BGR)
      snapshot_test();
    if (data_type  == DataTypes::Enum::MJPEG)
      jpeg_snapshot_test();


    begin = std::chrono::steady_clock::now();
    int time_diff = 0, count = 0;
    unsigned char * test_frame;
    while (time_diff <= 1000){

      test_frame = jpeg_test->get_buffer();
      count ++;
      end= std::chrono::steady_clock::now();
      time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    }
    std::cout << "Framerate test " <<  count << " FPS" << std::endl;

    /*
    * Testing APLR calls with raw data
    */
    int x = 0;
    std::cout << std::endl << "**** V4Pi ALPR demo ****" << std::endl<< std::endl;
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
    std::cin.ignore();

    /*
    * Testing APLR calls with Mat file
    */
    x = 0;
    std::cout << std::endl << "**** V4Pi OpenCV ALPR demo ****" << std::endl<< std::endl;
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
