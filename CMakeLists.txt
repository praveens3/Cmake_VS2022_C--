cmake_minimum_required(VERSION  3.10.0)

project(TestProj VERSION 0.1.0.0 DESCRIPTION test-c++-cmake-project LANGUAGES C CXX)

add_executable(testpro src/test.cpp)

set_property(TARGET testpro PROPERTY CXX_STANDARD 11)

# For Debug and Release configurations (Visual Studio has multiple configurations)
# RUNTIME_OUTPUT_DIRECTORY: This is where executables will be placed.
# LIBRARY_OUTPUT_DIRECTORY: This is where shared libraries (DLLs) will be placed.
# ARCHIVE_OUTPUT_DIRECTORY: This is where static libraries will be placed.
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/x64") not working
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/x64") not working

#for Download conan package in Terminal/cmd promt
# conan install . --build=missing --output-folder=build -s build_type=Debug //for debug
# conan install . --build=missing --output-folder=build // for release

# Add the path where spdlog-config.cmake is located
# Replace /path/to/spdlog-config with the actual path to your spdlog installation
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${CMAKE_BINARY_DIR}/generators/")

find_package(spdlog REQUIRED)
target_link_libraries(testpro PRIVATE spdlog::spdlog)