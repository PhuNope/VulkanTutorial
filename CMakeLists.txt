cmake_minimum_required(VERSION 3.31)
project(VulkanTutorial)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
find_package(Vulkan QUIET)

message(STATUS "ENV VULKAN_SDK = $ENV{VULKAN_SDK}")
message(STATUS "CMAKE_SIZEOF_VOID_P = ${CMAKE_SIZEOF_VOID_P}")

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/glfw/include
)

find_package(Vulkan REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Vulkan::Vulkan)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
