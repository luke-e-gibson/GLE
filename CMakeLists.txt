cmake_minimum_required(VERSION 3.0.0)
project(gle VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
find_package(spdlog REQUIRED)


file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.h", "src/*.c" "src/*.hpp")
add_executable(gle ${SRCS})
target_link_libraries(gle spdlog fmt glfw)