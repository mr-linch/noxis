cmake_minimum_required(VERSION 2.8)

project(Noxis)

set(CLASSES
    Engine
    Scene
)

set(HEADERS
    ns.hpp
    Noxis.hpp
)

set(SOURCES

)

foreach(CLASS ${CLASSES})
    list(APPEND HEADERS ${CLASS}.hpp)
    list(APPEND SOURCES ${CLASS}.cpp)
endforeach(CLASS)

add_library(noxis
    ${HEADERS}
    ${SOURCES}
)
