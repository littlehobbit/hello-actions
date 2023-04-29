cmake_minimum_required(VERSION 3.15)
project(hello_actions)

option(BUILD_TESTS OFF)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)

set(STATUS "VERSION_MAJOR is ${VERSION_MAJOR}")
set(STATUS "VERSION_MINOR is ${VERSION_MINOR}")
set(STATUS "VERSION_PATCH is ${VERSION_PATCH}")

configure_file(build_info.h.in build_info.h)

add_library(
  version_accessor STATIC
  src/version_accessor.cpp
)

target_include_directories(version_accessor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(version_accessor PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_compile_options(version_accessor PRIVATE -Wall -Wpedantic -Werror)
# target_compile_features(version_accessor PRIVATE cxx_std_17)
set_target_properties(version_accessor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE version_accessor)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wpedantic -Werror)
# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# TODO: cli target
# TODO: 


if (${BUILD_TESTS})
  enable_testing()
  add_subdirectory(tests)
endif()

# TODO: cpack for deb packages