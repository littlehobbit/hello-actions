#include <iostream>

#include <version_accessor.h>

int main(int argc, char* argv[]) {
  constexpr auto version = version::get_version();
  std::cout << "Version is " << version.to_string() << std::endl;
  std::cout << "Hello, World!" << std::endl;
  std::cout << "Hello, GitHub Actions!" << std::endl;
}