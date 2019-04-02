file(GLOB server_srcs ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp)
add_library(libServer OBJECT ${server_srcs})
