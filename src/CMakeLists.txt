add_library(libServerMain OBJECT
        main.cpp
        )

set(server_srcs
    $<TARGET_OBJECTS:libServerMain>
    $<TARGET_OBJECTS:libServer>)

add_subdirectory(server)
add_executable(${PROJECT_NAME} ${server_srcs})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} ${Boost_SYSTEM_LIBRARY})
