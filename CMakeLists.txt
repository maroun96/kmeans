# CMakeLists.txt

# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

#Project name
project(kmeans)

# Set the C++ standard to C++11 (or a later version if you prefer)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the directory where Point.h is located
include_directories(include)

# Automatically find all .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Add the executable target for the main program
add_executable(main main.cpp ${SOURCES})