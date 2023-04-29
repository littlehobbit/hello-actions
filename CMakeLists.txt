cmake_minimum_required(VERSION 3.15)
project(hello_actions)

option(BUILD_TESTS OFF)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)

configure_file(build_info.h.in build_info.h)

add_library(
  version_accessor STATIC
  src/version_accessor.cpp
)

target_include_directories(version_accessor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(version_accessor PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_compile_options(version_accessor PRIVATE -Wall -Wpedantic -Werror)
set_target_properties(version_accessor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE version_accessor)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wpedantic -Werror)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)


if (${BUILD_TESTS})
  enable_testing()
  add_subdirectory(tests)
endif()

# TODO: cpack for deb packages