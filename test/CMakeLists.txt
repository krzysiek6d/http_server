include_directories(${PROJECT_SOURCE_DIR}/3rdparty/gtest)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
add_subdirectory(ut)
include(CTest)