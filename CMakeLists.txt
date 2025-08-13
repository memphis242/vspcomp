# 3.13 just so my README.md for basic instructions to build /w -S and -B are valid
cmake_minimum_required (VERSION 3.13)

project (vspcomp VERSION 0.1.0 LANGUAGES CXX)

# Collect all source files in src/
file(GLOB SRC_FILES src/*.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include cfg)

# Find and link libfmt from system
find_package(fmt REQUIRED) # TODO: Specify minimum version
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
