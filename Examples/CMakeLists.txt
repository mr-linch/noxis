cmake_minimum_required(VERSION 2.8)

aux_source_directory(. EXAMPLES)

include_directories(
    ${NoxisEngine_SOURCE_DIR}/
)

link_directories(
    ${NoxixEngine_BINARY_DIR}/Noxis
)


foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXECUTABLE ${EXAMPLE} NAME_WE)
    add_executable(${EXECUTABLE} ${EXAMPLE})
    target_link_libraries(${EXECUTABLE} noxis ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
endforeach(EXAMPLE)

add_custom_target(run
    COMMAND simple_example 
    DEPENDS simple_example
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

