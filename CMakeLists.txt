set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8)
project(openALPR_test)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package( OpenCV REQUIRED )
#add_executable( DisplayImage DisplayImage.cpp )
#target_link_libraries( DisplayImage ${OpenCV_LIBS} )

SET(OPENALPR_LIB /home/pi/openalpr/src/build/openalpr/libopenalpr.so)
SET(OPENALPR_TEST openALPR_test)
include_directories(Headers)
file(GLOB SOURCES
    Headers/*.h
    Sources/*.cpp
)
add_executable(${OPENALPR_TEST} ${SOURCES} main.cpp)

target_link_libraries(openALPR_test ${OPENALPR_LIB})
