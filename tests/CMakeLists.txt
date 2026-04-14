# tests/CMakeLists.txt

# Создаем тестовый исполняемый файл
add_executable(point_counter_tests
    test_point_counter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/point_counter.cpp
)

# Добавляем пути к заголовкам
target_include_directories(point_counter_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# Линкуем с Google Test
target_link_libraries(point_counter_tests
    GTest::gtest_main
)

# Регистрируем тесты
enable_testing()

include(GoogleTest)
gtest_discover_tests(point_counter_tests)