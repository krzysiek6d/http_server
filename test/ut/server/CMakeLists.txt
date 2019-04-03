set(test_name server_tests)

file(GLOB test_sources *.cpp **/*.cpp **/**/*.cpp)

list(LENGTH test_sources test_sources_len)
if(test_sources_len GREATER 0)
    add_executable(${test_name}
            $<TARGET_OBJECTS:gtest>
            $<TARGET_OBJECTS:libHttp>
            ${test_sources})

    target_link_libraries(
            ${test_name}
            ${CMAKE_THREAD_LIBS_INIT}
    )

    add_dependencies(
            ut
            ${test_name}
    )

    add_test(
            NAME ${test_name}
            COMMAND ${test_name}
    )

    set_tests_properties(${test_name} PROPERTIES LABELS UT)
endif(test_sources_len GREATER 0)
