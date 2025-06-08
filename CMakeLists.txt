cmake_minimum_required(VERSION 3.16)
project(MiniRT C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Output binary
set(EXECUTABLE_NAME MiniRT)

# Add libft (assumes it's already built with its own make)
add_subdirectory(libft)

# Build MLX42 from source
add_subdirectory(MLX42)

# Platform-specific settings
if(APPLE)
    message(STATUS "Configuring for macOS")
    find_package(PkgConfig REQUIRED)
    pkg_search_module(GLFW REQUIRED glfw3)

    include_directories(/opt/homebrew/include)
    link_directories(/opt/homebrew/lib)

    # Apple frameworks for MLX42
    find_library(COCOA_FRAMEWORK Cocoa)
    find_library(METAL_FRAMEWORK Metal)
    find_library(QUARTZCORE_FRAMEWORK QuartzCore)
endif()

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/libft
    ${PROJECT_SOURCE_DIR}/MLX42/include
)

# Source files
file(GLOB_RECURSE SRC_FILES
    src/*.c
)

# Executable
add_executable(${EXECUTABLE_NAME} ${SRC_FILES})

# Link libraries
target_link_libraries(${EXECUTABLE_NAME}
    ft
    mlx42
    ${GLFW_LIBRARIES}
    ${COCOA_FRAMEWORK}
    ${METAL_FRAMEWORK}
    ${QUARTZCORE_FRAMEWORK}
    m
)
