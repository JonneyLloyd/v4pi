#include "demo_day.h"

// Below command is needed to launch Pi Camera driver
//sudo modprobe bcm2835-v4l2

/*
* Snapshot function to save ppm image
*/
void DemoDay::snapshot_test()
{
  std::cout << std::endl << "Snapshot test" << std::endl;
  begin = std::chrono::steady_clock::now();
  v4pi->snapshot();
  end= std::chrono::steady_clock::now();
  std::cout << "Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;

  frame = v4pi->get_cv_mat();
  std::cout << std::endl << "CV Snapshot test" << std::endl;
  begin = std::chrono::steady_clock::now();
  frame = v4pi->get_cv_mat();
  imwrite("imageCV.ppm", frame);
  end= std::chrono::steady_clock::now();
  std::cout << "CV Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;
}

/*
* Snapshot function when MJPEG format has been used
*/
void DemoDay::jpeg_snapshot_test()
{
  std::cout << std::endl << "Snapshot test" << std::endl;
  begin = std::chrono::steady_clock::now();

  v4pi->save_jpeg("out.jpg");
  end = std::chrono::steady_clock::now();
  std::cout << "Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;

  std::cout << std::endl << "CV Snapshot test" << std::endl;
  begin = std::chrono::steady_clock::now();
  frame = v4pi->get_cv_mat();
  imwrite("imageCV.jpg", frame);
  end = std::chrono::steady_clock::now();
  std::cout << "CV Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;
}

/*
* Testing APLR calls with raw data
*/
void DemoDay::alpr(){
  int x = 0;
  std::cout << "Raw data " << std::endl;
  while(x < 5){
    x++;
    std::cout << "Loop start" << std::endl;
    begin = std::chrono::steady_clock::now();
    switch(data_type) {
        case DataTypes::Enum::YU12  :
        alprJpeg.run(v4pi->get_buffer(),  1, width, height);
        break;

        case DataTypes::Enum::MJPEG  :
        frame = (cv::imdecode(cv::Mat(height,width, CV_8UC3, v4pi->get_buffer()),1));
        alprJpeg.run(frame);
        break;

        case DataTypes::Enum::RGB  :
        frame = cv::Mat(height,width, CV_8UC3, v4pi->get_buffer());
        cv::cvtColor(frame, frame, cv::COLOR_RGB2BGR);
        alprJpeg.run(frame);
        break;

        case DataTypes::Enum::BGR  :
        alprJpeg.run(v4pi->get_buffer(),  3, width, height);
        break;

        default :
        std::cout << "Unsupported format!" << std::endl;
  }
    end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
  }
}

/*
* Saves an avi video at 24 FPS
*/
void DemoDay::video_test()
{
  std::cout << std::endl << "Video test" << std::endl;
  cv::VideoWriter video("out.avi",CV_FOURCC('D','I','V','X'),24, cv::Size(width, height),true);
  int count = 0;
  while (count < 200){
    frame = v4pi->get_cv_mat();
    video.write(frame);
    count++;
  }
  std::cout << std::endl << "Video test complete" << std::endl;
}

/*
* cv_snap tests a pute OpenCV implementation of snapshot
*/
void DemoDay::cv_snap()
{
  cv::VideoCapture cap(0);
  if ( !cap.isOpened() )
  {
       std::cout << "Cannot open the web cam" << std::endl;
       exit(0);

  }
  cv::Mat frame;
  cap.set(CV_CAP_PROP_FRAME_WIDTH, width);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, height);
  compression_params.push_back(cv::IMWRITE_JPEG_QUALITY );

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  std::chrono::steady_clock::time_point end;
  cap >> frame; // get a new frame from camera
  imwrite("imageCV.jpg", frame, compression_params);
  end= std::chrono::steady_clock::now();
  std::cout << "**** Snapshot test, pure CV **** = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
  std::cout << std::endl << "Press ENTER to continue" << std::endl;
  std::cin.ignore();

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
  std::cout << std::endl << "OpenCV Framerate test " <<  count << std::endl << std::endl;
  std::cout << "End of OpenCV demo" << std::endl;
  cap.release();
}

/*
* test sighthound
* Internet connection and sighthound api access key required
*/
void DemoDay::sighthound(){
  std::string key = "Insert Sighthound token here";
  std::cout << std::endl << "V4Pi Sighthound" << std::endl;
  begin = std::chrono::steady_clock::now();
  v4pi->save_jpeg("out.jpg");
  v4pi->sighthound(key.c_str());
  end = std::chrono::steady_clock::now();
  std::cout << std::endl << "V4Pi Sighthound time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;

  std::cout << std::endl << "CV Sighthound" << std::endl;
  begin = std::chrono::steady_clock::now();
  frame = v4pi->get_cv_mat();
  imwrite("out.jpg", frame);
  v4pi->sighthound(key.c_str());
  end = std::chrono::steady_clock::now();
  std::cout << std::endl << "CV Sighthound time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;
}

//main function
int DemoDay::cam_test()
{
  //create factory
  factory = new V4l2Factory();
  //select data type from data_types_enum.h
  data_type = DataTypes::Enum::BGR;
  std::cout << std::endl << "**** V4Pi BGR image format demo ****" << std::endl<< std::endl;
  //select device address video0 is default camera
  address = "/dev/video0";
  //set V4l2Interface jpeg test equal to intialised factory
  v4pi = factory->init(address, width, height, data_type, framerate);
  //call init function to start V4Pi
  v4pi->init();
  cv::Mat test_pic;
  test_pic = cv::Mat(height, width, CV_8UC3, v4pi->get_buffer());
  cv::imwrite("test.bmp", test_pic);  //sanity check
  snapshot_test();
  std::cout << std::endl << "Press ENTER to continue" << std::endl;
  std::cin.ignore();

  std::cout << std::endl << "**** V4Pi YU12 image format demo ****" << std::endl<< std::endl;
  v4pi->teardown();
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::YU12;
  address = "/dev/video0";
  v4pi = factory->init(address, width, height, data_type, framerate);
  v4pi->init();
  test_pic = cv::Mat(height, width, CV_8UC1, v4pi->get_buffer());
  snapshot_test();
  std::cout << std::endl << "Press ENTER to continue" << std::endl;
  std::cin.ignore();

  std::cout << std::endl << "**** V4Pi RGB image format demo ****" << std::endl<< std::endl;
  v4pi->teardown();
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::RGB;
  address = "/dev/video0";
  v4pi = factory->init(address, width, height, data_type, framerate);
  v4pi->init();
  test_pic = cv::Mat(height, width, CV_8UC3, v4pi->get_buffer());
  snapshot_test();
  std::cout << std::endl << "Press ENTER to continue" << std::endl;
  std::cin.ignore();

  std::cout << std::endl << "**** V4Pi MJPEG image format demo ****" << std::endl<< std::endl;
  v4pi->teardown();
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::MJPEG;
  address = "/dev/video0";
  v4pi = factory->init(address, width, height, data_type, framerate);
  v4pi->init();
  test_pic = cv::imdecode(cv::Mat(height,width, CV_8UC3, v4pi->get_buffer()),1);
  jpeg_snapshot_test();
  std::cout << std::endl << "Press ENTER to continue" << std::endl;
  std::cin.ignore();
  v4pi->teardown();

  std::cout << std::endl << "**** V4Pi ALPR demo ****" << std::endl<< std::endl;
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::YU12;
  address = "/dev/video0";
  v4pi = factory->init(address, width, height, data_type, framerate);
  v4pi->init();
  alpr();
  std::cout << std::endl << "Press ENTER to continue" << std::endl;
  std::cin.ignore();

  begin = std::chrono::steady_clock::now();
  int time_diff = 0, count = 0;
  unsigned char * test_frame;
  while (time_diff <= 1000){

    test_frame = v4pi->get_buffer();
    count ++;
    end= std::chrono::steady_clock::now();
    time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
  }
  std::cout << "Framerate test " <<  count << " FPS" << std::endl;
  v4pi->teardown();
  std::cout << std::endl << "Press ENTER to continue" << std::endl;
  std::cin.ignore();

  std::cout << std::endl << "**** Pure OpenCV implementation demo ****" << std::endl<< std::endl;
  cv_snap();
  std::cout << std::endl << "Press ENTER to continue" << std::endl;
  std::cin.ignore();

  factory = new V4l2Factory();
  data_type = DataTypes::Enum::BGR;
  address = "/dev/video0";
  v4pi = factory->init(address, width, height, data_type, framerate);
  v4pi->init();

  std::cout << std::endl << "**** V4Pi Video demo ****" << std::endl<< std::endl;
  video_test();

  v4pi->teardown();
  std::cout << std::endl << "Press ENTER to continue" << std::endl;
  std::cin.ignore();

  std::cout << std::endl << "**** V4Pi sighthound demo ****" << std::endl<< std::endl;
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::MJPEG;
  address = "/dev/video0";
  v4pi = factory->init(address, 1280, 720, data_type, 30);
  v4pi->init();

  sighthound();

  v4pi->teardown();

  return 0;
}
