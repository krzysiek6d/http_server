project(http_server)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

find_package(Boost COMPONENTS system REQUIRED)
find_package(Threads)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(src)
add_subdirectory(3rdparty)

enable_testing()
add_subdirectory(test EXCLUDE_FROM_ALL)
