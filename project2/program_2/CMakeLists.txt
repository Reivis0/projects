cmake_minimum_required(VERSION 3.22.0)
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(Program_2)

include_directories(sources)

set(SOURCES
    sources/main.cpp
    sources/client.cpp
    sources/outputData.cpp
)

set(HEADERS
    sources/client.h
    sources/outputData.h
)

add_executable(Program_2 ${SOURCES} ${HEADERS})
