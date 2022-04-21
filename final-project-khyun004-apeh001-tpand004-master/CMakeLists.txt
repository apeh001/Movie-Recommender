CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(movieList main.cpp movieList.cpp movieList.hpp filter.hpp )
ADD_EXECUTABLE(test test.cpp movieList.cpp movieList.hpp filter.hpp )

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
