cmake_minimum_required(VERSION 3.20)
project(PointsInCircle)

set(CMAKE_CXX_STANDARD 17)

add_executable(PointsInCircle
    src/main.cpp
    src/point_counter.cpp
)

target_include_directories(PointsInCircle PRIVATE include)

# Подключаем тесты
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    FetchContent_MakeAvailable(googletest)
    
    add_subdirectory(tests)
endif()