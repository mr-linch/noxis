cmake_minimum_required(VERSION 2.8)

project(NoxisEngine)

list(APPEND CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

add_subdirectory(Noxis)
add_subdirectory(Examples)



