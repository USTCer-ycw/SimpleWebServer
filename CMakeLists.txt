cmake_minimum_required(VERSION 3.10)
project(SimpleWebServer)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(src/net)

add_subdirectory(src/base)

add_definitions(-g)

add_executable(SimpleWebServer main.cpp)

target_link_libraries(SimpleWebServer net)

target_link_libraries(SimpleWebServer base)