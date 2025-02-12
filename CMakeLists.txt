# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(kmeans VERSION 0.0.1 DESCRIPTION "C++ implementation of k-means")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the directory where headers are located
include_directories(include)

# List source files explicitly
set(SOURCES
    src/utils.cpp
    src/kmeans.cpp
)

# Create a shared library
add_library(kmeans SHARED ${SOURCES})

# Specify where to place the compiled library
set_target_properties(kmeans PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Enable testing
enable_testing()

# Add the tests directory
add_subdirectory(tests)
