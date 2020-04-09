# Init
cmake_minimum_required(VERSION 3.2)
project(SSandbox)

cmake_policy(SET CMP0074 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    add_definitions(-D_WIN32_WINNT=0x0A00) 
endif(MSVC)

add_subdirectory(cmake)
add_subdirectory(dep)
add_subdirectory(src)
add_subdirectory(misc)