project(mem_leak_detect)
cmake_minimum_required(VERSION 2.8)

include_directories(thirdparts\concurrentqueue)
include_directories(thirdparts\gperftools)
include_directories(thirdparts\lz4)
include_directories(thirdparts\zmq)

link_directories(thirdparts\gperftools)
link_directories(thirdparts\lz4)
link_directories(thirdparts\zmq)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wno-unused-local-typedefs -Wno-unused-variable -Wno-literal-suffix -D__STDC_FORMAT_MACROS -std=c++11 -fpermissive")
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -g -Wall")

add_subdirectory(src)

