#include "demo_day.h"


//sudo modprobe bcm2835-v4l2
//sudo sshfs -o allow_other,default_permissions pi@192.168.1.101:/home/pi/FYP/ /mnt/raspberry/
void DemoDay::snapshot_test()
{
  std::cout << std::endl << "Snapshot test" << std::endl;

  begin = std::chrono::steady_clock::now();
  jpeg_test->snapshot();
  end= std::chrono::steady_clock::now();
  std::cout << "Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;

  frame = jpeg_test->get_cv_mat();
  std::cout << std::endl << "CV Snapshot test" << std::endl;
  begin = std::chrono::steady_clock::now();
  frame = jpeg_test->get_cv_mat();
  imwrite("imageCV.ppm", frame);
  end= std::chrono::steady_clock::now();
  std::cout << "CV Snapshot time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl <<std::endl;

}

void DemoDay::jpeg_snapshot_test()
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

void DemoDay::alpr(){
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
}

void DemoDay::video_test()
{
  std::cout << std::endl << "Video test" << std::endl;
  cv::VideoWriter video("out.avi",CV_FOURCC('D','I','V','X'),24, cv::Size(width, height),true);
  int count = 0;
  while (count < 200){
    frame = jpeg_test->get_cv_mat();
    video.write(frame);

    count++;
  }
  std::cout << std::endl << "Video test complete" << std::endl;
}

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
    //cap >> frame; // get a new frame from camera
    //imwrite("imageCV.jpg", frame, compression_params); //sanity check


    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end;

    cap >> frame; // get a new frame from camera
    imwrite("imageCV.jpg", frame, compression_params);

    end= std::chrono::steady_clock::now();
    std::cout << "**** Snapshot test, pure CV **** = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;

    std::cin.ignore();
    std::cout << "**** OpenCV APLR test ****" << std::endl  << std::endl;
    int x = 0;

    while(x < 5){
    x++;
    begin = std::chrono::steady_clock::now();
    std::cout << "Loop start" << std::endl;
    cap >> frame; // get a new frame from camera

    alprJpeg.run(frame);
    end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
  }

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

}


int DemoDay::cam_test()
{
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::BGR;
  std::cout << std::endl << "**** V4Pi BGR image format demo ****" << std::endl<< std::endl;
  address = "/dev/video0";
  jpeg_test = factory->init(address, width, height, data_type, framerate);
  jpeg_test->init();
  cv::Mat test_pic;



  test_pic = cv::Mat(height, width, CV_8UC3, jpeg_test->get_buffer());
  cv::imwrite("test.bmp", test_pic);  //sanity check
  snapshot_test();
  std::cin.ignore();

  std::cout << std::endl << "**** V4Pi RGB image format demo ****" << std::endl<< std::endl;
  jpeg_test->teardown();
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::RGB;
  address = "/dev/video0";
  jpeg_test = factory->init(address, width, height, data_type, framerate);
  jpeg_test->init();
  test_pic = cv::Mat(height, width, CV_8UC3, jpeg_test->get_buffer());
  snapshot_test();
  std::cin.ignore();

  std::cout << std::endl << "**** V4Pi YU12 image format demo ****" << std::endl<< std::endl;
  jpeg_test->teardown();
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::YU12;
  address = "/dev/video0";
  jpeg_test = factory->init(address, width, height, data_type, framerate);
  jpeg_test->init();
  test_pic = cv::Mat(height, width, CV_8UC1, jpeg_test->get_buffer());
  snapshot_test();
  std::cin.ignore();

  std::cout << std::endl << "**** V4Pi MJPEG image format demo ****" << std::endl<< std::endl;
  jpeg_test->teardown();
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::MJPEG;
  address = "/dev/video0";
  jpeg_test = factory->init(address, width, height, data_type, framerate);
  jpeg_test->init();
  test_pic = cv::imdecode(cv::Mat(height,width, CV_8UC3, jpeg_test->get_buffer()),1);
  jpeg_snapshot_test();
  std::cin.ignore();
  jpeg_test->teardown();

  std::cout << std::endl << "**** Pure OpenCV implementation demo ****" << std::endl<< std::endl;
  cv_snap();
  std::cin.ignore();

  std::cout << std::endl << "**** V4Pi ALPR demo ****" << std::endl<< std::endl;
  factory = new V4l2Factory();
  data_type = DataTypes::Enum::BGR;
  address = "/dev/video0";
  jpeg_test = factory->init(address, width, height, data_type, framerate);
  jpeg_test->init();
  alpr();
  std::cin.ignore();

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


  std::cout << std::endl << "**** V4Pi Video demo ****" << std::endl<< std::endl;
  video_test();

  std::cout << std::endl << "**** V4Pi sighthound demo ****" << std::endl<< std::endl;
  jpeg_test->sighthound();

  jpeg_test->teardown();

  return 0;
}
