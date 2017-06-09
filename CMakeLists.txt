set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8)
project(openALPR_test)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(OPENALPR_LIB /home/pi/openalpr/src/build/openalpr/libopenalpr.so)
SET(OPENALPR_TEST openALPR_test)
add_executable(${OPENALPR_TEST} test.cpp)
target_link_libraries(openALPR_test ${OPENALPR_LIB})

