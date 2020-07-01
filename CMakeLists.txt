project(mem_leak_detect)
cmake_minimum_required(VERSION 2.8)

# enable test
enable_testing()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wno-unused-local-typedefs -Wno-unused-variable -Wno-literal-suffix -D__STDC_FORMAT_MACROS -fpermissive")
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -std=c++11 -g -Wall -fPIC")

# 将目录下文件都设置到DIR_LIB_SRCS变量中
#aux_source_directory(./threads DIR_LIB_SRCS)

add_subdirectory(src)

