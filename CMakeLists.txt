cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 26)

project(the_cookie_lib)

list(APPEND string_utils source/string/String.cpp source/string/StrLen.cpp)
include_directories(include/string)

list(APPEND memory_utils source/memory/MemDup.cpp)
include_directories(include/memory)

list(APPEND vector_utils)

list(APPEND matrix_utils)

add_library(the_cookie_lib ${string_utils} ${memory_utils}
        include/memory/MemDup.hpp
        include/string/StrLen.hpp
        include/memory/Memory.hpp)

set_target_properties(the_cookie_lib PROPERTIES PREFIX "")
set_target_properties(the_cookie_lib PROPERTIES OUTPUT_NAME "the_cookie_lib")
set_target_properties(the_cookie_lib PROPERTIES SUFFIX ".a")