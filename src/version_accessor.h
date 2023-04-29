#ifndef __VERSION_ACCESSSOR_H_8N5MG3R92SMF__
#define __VERSION_ACCESSSOR_H_8N5MG3R92SMF__

#include <cstdint>
#include <string_view>

#include "build_info.h"

namespace version {
struct Version {
  uint32_t major;
  uint32_t minor;
  uint32_t patch;

  constexpr std::string_view to_string() const {
    return VERSION_STR;
  }

private:
  Version() = default;
};

// TODO: add compile-time access
constexpr Version get_version() {
  return {VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH};
}

} // namespace version

#endif // __VERSION_ACCESSSOR_H_8N5MG3R92SMF__
