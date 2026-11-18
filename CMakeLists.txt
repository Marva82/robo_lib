cmake_minimum_required(VERSION 3.16)
project(robo_lib CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -fsanitize=address,undefined -g)
add_link_options(-fsanitize=address,undefined)

find_package(Eigen3 REQUIRED)
find_package(GTest REQUIRED)

add_library(robo src/robo.cpp)
target_include_directories(robo PUBLIC src)
target_link_libraries(robo PUBLIC Eigen3::Eigen)

add_executable(robo_tests tests/test_robo.cpp)
target_link_libraries(robo_tests robo GTest::gtest_main)
enable_testing()
add_test(NAME robo_tests COMMAND robo_tests)
