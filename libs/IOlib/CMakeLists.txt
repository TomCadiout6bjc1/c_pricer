cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)

set(LIBRARY_NAME IOlib)
set(LIBRARY_VERSION "1.0.1")
set(LIBRARY_DESCRIPTION "IO library by Charles-Auguste GOURIO")

project(${LIBRARY_NAME} VERSION ${LIBRARY_VERSION} DESCRIPTION ${LIBRARY_DESCRIPTION})

# Create the library
add_library(${LIBRARY_NAME} SHARED)

# Gather source files for ImpliedVolatilitySurface
file(GLOB LIBRARY_SRC "src/*.cpp")

# Include directories for the library
target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Add source files to the library
target_sources(${LIBRARY_NAME} PRIVATE
    ${LIBRARY_SRC}
)

# Test executable
add_executable(test_${LIBRARY_NAME} test/main.cpp)

# Link the library to the test executable
target_link_libraries(test_${LIBRARY_NAME} PRIVATE ${LIBRARY_NAME})

