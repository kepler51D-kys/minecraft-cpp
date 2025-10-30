cmake_minimum_required(VERSION 3.10)
project(minecraft VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

# Create executable
add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    libs/shaders.cpp
    libs/voxels.cpp
    libs/voxelInfo.cpp
)

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    OpenGL::GL 
    glfw 
    GLEW::GLEW
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR} include)

# Compiler options
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

# Set properties for better OpenGL support
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)