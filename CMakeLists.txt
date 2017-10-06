set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8)
project(fyp)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package( OpenCV REQUIRED )

SET(OPENALPR_LIB /home/pi/openalpr/src/build/openalpr/libopenalpr.so)
SET(FYP fyp)
include_directories(Headers)
file(GLOB SOURCES
    Headers/*.h
    Sources/*.cpp
)
add_executable(${FYP} ${SOURCES} main.cpp)

target_link_libraries(${FYP} ${OPENALPR_LIB} ${OpenCV_LIBS} )
