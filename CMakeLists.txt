cmake_minimum_required(VERSION 3.10)

# Set the project name
project(UNIQUE_ID_GENERATOR)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add the executable
add_executable(UNIQUE_ID_GENERATOR src/Main.cpp)