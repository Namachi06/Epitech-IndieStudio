## Set CMake configuration
cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

## Set project name
set(NAME bomberman)
project(${NAME})

find_package(Irrlicht REQUIRED)
find_package(SFML REQUIRED COMPONENTS network audio graphics window system)

if(UNIX)
    ## Add compilation flags
    add_definitions(-W -Wall -Wextra -g -isystem ${Irrlicht_INCLUDE_DIRS})

    find_package(X11 REQUIRED)

    include_directories(
        ${Irrlicht_INCLUDE_DIRS}
        ${SFML_INCLUDE_DIR}
        ${X11_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/include
    )
endif(UNIX)

if(WIN32)
    include_directories(
        ${Irrlicht_INCLUDE_DIRS}
        ${SFML_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/irrKlang/include
    )
endif(WIN32)


# Get source files in SRCS variable
file(GLOB_RECURSE SRCS src/*.cpp)
# Get headers files in HDRS variable
file(GLOB_RECURSE HDRS include/*.hpp)

add_executable(${NAME}
    ${SRCS}
    ${HDRS}
)

if(UNIX)
    target_link_libraries(${NAME}
        ${Irrlicht_LIBRARIES}
        ${SFML_LIBRARIES}
        ${SFML_DEPENDENCIES}
        ${X11_LIBRARIES}
    )
endif(UNIX)

if(WIN32)
    target_link_libraries(${NAME}
        ${Irrlicht_LIBRARIES}
        ${SFML_LIBRARIES}
        ${SFML_DEPENDENCIES}
    )
endif(WIN32)
