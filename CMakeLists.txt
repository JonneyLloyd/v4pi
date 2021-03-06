set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8)
project(fyp)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_TYPE Debug)

find_package( OpenCV REQUIRED )
find_package(OpenMP)
set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS} ${CURL_LIBRARIES}")
endif()

SET(OPENALPR_LIB /home/pi/openalpr/src/build/openalpr/libopenalpr.so)
SET(FYP fyp)
include_directories(Headers)
file(GLOB SOURCES
    Headers/*.h
    Sources/*.cpp
)
add_executable(${FYP} ${SOURCES} main.cpp)

target_link_libraries(${FYP} ${OPENALPR_LIB} ${OpenCV_LIBS} )
