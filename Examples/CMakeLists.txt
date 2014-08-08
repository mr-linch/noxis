set(EXAMPLES
    example.cpp
)

include_directories(
    ${NoxisEngine_SOURCE_DIR}/
)

link_directories(
    ${NoxixEngine_BINARY_DIR}/Noxis
)

foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXECUTABLE ${EXAMPLE} NAME_WE)
    add_executable(${EXECUTABLE} ${EXAMPLE})
    target_link_libraries(${EXECUTABLE} noxis SDL2)
endforeach(EXAMPLE)

