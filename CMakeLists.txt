cmake_minimum_required(VERSION  3.10.0)

# Define the main project
project(TestProj VERSION 0.1.0.0 DESCRIPTION test-c++-cmake-project LANGUAGES C CXX)

# Add all .cpp and .h files in the src/myLib directory to the myLib library
file(GLOB myLib_SOURCES src/myLib/*.cpp src/myLib/*.h)

# Create the static library target for myLib
add_library(myLib STATIC ${myLib_SOURCES})

# Optionally, you can set include directories for the library if needed
# target_include_directories(myLib PUBLIC ${CMAKE_SOURCE_DIR}/src/myLib)

# Add the path where spdlog-config.cmake is located
# Replace /path/to/spdlog-config with the actual path to your spdlog installation
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${CMAKE_BINARY_DIR}/generators/")
find_package(spdlog REQUIRED)

# Link the connan package lib to the myLib lib
target_link_libraries(myLib PUBLIC spdlog::spdlog)

# Add all .cpp and .h files in the src/testpro directory to the testpro executable
file(GLOB testpro_SOURCES src/app/*.cpp src/app/*.h)

# Create the executable target for testpro
add_executable(testpro ${testpro_SOURCES})
target_include_directories(testpro PUBLIC ${CMAKE_SOURCE_DIR}/src/myLib)
target_link_libraries(testpro PRIVATE myLib)

# Set the C++ standard
set_property(TARGET testpro PROPERTY CXX_STANDARD 11)







# Notes 
# For Debug and Release configurations (Visual Studio has multiple configurations)
# RUNTIME_OUTPUT_DIRECTORY: This is where executables will be placed.
# LIBRARY_OUTPUT_DIRECTORY: This is where shared libraries (DLLs) will be placed.
# ARCHIVE_OUTPUT_DIRECTORY: This is where static libraries will be placed.

# Output directories for Debug and Release (optional, if needed)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/x64") not working
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/x64") not working

# F    or Download conan package in Terminal/cmd promt
# conan install . --build=missing --output-folder=build -s build_type=Debug //for debug
# conan install . --build=missing --output-folder=build // for release