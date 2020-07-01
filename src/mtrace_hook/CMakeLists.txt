cmake_minimum_required(VERSION 2.8)

message("dir is: " ${PROJECT_SOURCE_DIR})
include_directories("${PROJECT_SOURCE_DIR}/thirdpart")

link_directories("${PROJECT_SOURCE_DIR}/thirdpart/concurrentqueue")
link_directories("${PROJECT_SOURCE_DIR}/thirdpart/gperftools")
link_directories("${PROJECT_SOURCE_DIR}/thirdpart/lz4")
link_directories("${PROJECT_SOURCE_DIR}/thirdpart/zmq")

add_library(mtrace_hook SHARED ${file_src})
target_link_libraries(mtrace_hook pthread)