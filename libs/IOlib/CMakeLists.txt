cmake_minimum_required(VERSION 3.22)

set(LIBRARY_NAME IOlib)
set(LIBRARY_VERSION "1.0.1")
set(LIBRARY_DESCRIPTION "IO library by Charles-Auguste GOURIO")

project(${LIBRARY_NAME} VERSION ${LIBRARY_VERSION} DESCRIPTION ${LIBRARY_DESCRIPTION})

add_library(${LIBRARY_NAME} SHARED
    src/io.cpp
)

add_executable(run test/main.cpp src/io.cpp)

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)
target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

