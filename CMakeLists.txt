cmake_minimum_required(VERSION 3.6)
project(fiuba_taller2_tallerify_app_server)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        README.md src/api/main.cpp)

add_executable(fiuba_taller2_tallerify_app_server ${SOURCE_FILES})