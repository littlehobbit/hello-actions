#include <catch2/catch.hpp>

#include <sstream>
#include <version_accessor.h>

#include "build_info.h"

TEST_CASE("AccessorTest") {
  constexpr auto version = version::get_version();

  SECTION("GetVersion") {
    REQUIRE(version.major == VERSION_MAJOR);
    REQUIRE(version.minor == VERSION_MINOR);
    REQUIRE(version.patch == VERSION_PATCH);
  }

  SECTION("FormatVersion") {
    std::stringstream str_version;
    str_version << version.major << '.' << version.minor << '.'
                << version.patch;

    REQUIRE(version::get_version().to_string() == str_version.str());
  }
}
