cmake_minimum_required(VERSION 3.22.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MainProject)

set(PROJECTS
    program_1
    program_2
)

foreach(PROJECT ${PROJECTS})
    add_subdirectory(${PROJECT})
endforeach()

add_custom_target(RunAllPrograms
    COMMAND $<TARGET_FILE:Program_1>
    COMMAND $<TARGET_FILE:Program_2>
    DEPENDS ${PROJECTS}
)