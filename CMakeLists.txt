cmake_minimum_required(VERSION 3.15)
project(hello_actions)

option(BUILD_TESTS OFF)

if (NOT DEFINED VERSION_MAJOR)
  set(VERSION_MAJOR 0)
endif()

if (NOT DEFINED VERSION_MINOR)
  set(VERSION_MINOR 0)
endif()

if (NOT DEFINED VERSION_PATCH)
  set(VERSION_PATCH 0)
endif()

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

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT gataullinruslandev@gmain.com)
include(CPack)

