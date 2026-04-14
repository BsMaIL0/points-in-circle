add_executable(point_counter_tests
    test_point_counter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/point_counter.cpp
)

target_include_directories(point_counter_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(point_counter_tests GTest::gtest_main)

add_test(NAME PointCounterTests COMMAND point_counter_tests)