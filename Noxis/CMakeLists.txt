cmake_minimum_required(VERSION 2.8)

project(Noxis)

set(CLASSES
    Engine
    Scene
    Node
    Logger
    LogHandler
)

set(HEADERS
    ns.hpp
    Noxis.hpp
    utils.hpp
    Point2D.hpp
    Size2D.hpp
)

set(SOURCES
    utils.cpp
)

foreach(CLASS ${CLASSES})
    list(APPEND HEADERS ${CLASS}.hpp)
    list(APPEND SOURCES ${CLASS}.cpp)
endforeach(CLASS)

add_library(noxis
    ${HEADERS}
    ${SOURCES}
)
