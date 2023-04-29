cmake_minimum_required(VERSION 3.10)

project(version_accessor_tests)

find_package(GTest REQUIRED)
include(GoogleTest)


add_executable(
  ${PROJECT_NAME}
  test_version_accessor.cpp
)

target_link_libraries(
  ${PROJECT_NAME} PRIVATE
  GTest::GTest
  GTest::Main
  version_accessor
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

gtest_discover_tests(${PROJECT_NAME})

