cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
project( pinstats )
set (CMAKE_CXX_STANDARD 14)
find_package( OpenCV REQUIRED )
add_executable( pinstats pinstats.cpp )
add_executable( calib calib.cpp )
target_link_libraries( pinstats ${OpenCV_LIBS} )
target_link_libraries( calib ${OpenCV_LIBS} )
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_BUILD_TYPE RELEASE)
