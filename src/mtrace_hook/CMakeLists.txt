#.h
#.cpp
aux_source_directory(./ file_src)
#.exe
add_library(mtrace_hook SHARED ${file_src})
target_link_libraries(mtrace_hook pthread)