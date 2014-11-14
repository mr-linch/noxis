cmake_minimum_required(VERSION 2.8)

project(Noxis)

aux_source_directory(. SOURCES)

add_library(noxis STATIC ${SOURCES})
