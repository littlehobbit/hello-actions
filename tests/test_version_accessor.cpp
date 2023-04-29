#include <gtest/gtest.h>

#include <sstream>
#include <version_accessor.h>

#include "build_info.h"

TEST(AccessorTest, GetVersion) {
  constexpr auto version = version::get_version();
  ASSERT_EQ(version.major, VERSION_MAJOR);
  ASSERT_EQ(version.minor, VERSION_MINOR);
  ASSERT_EQ(version.patch, VERSION_PATCH);
}

TEST(AccessorTest, FormatVersion) {
  auto version = version::get_version();
  
  std::stringstream str_version;
  str_version << version.major << '.' << version.minor << '.' << version.patch;
  
  ASSERT_EQ(version::get_version().to_string(), str_version.str());
}
