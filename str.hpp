#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace util {

template <typename... Arg>
std::string cat(Arg&&... arg) {
  std::ostringstream ss;
  (void)(ss << ... << std::forward<Arg>(arg));
  return ss.str();
}

template <typename Container>
std::string join(Container c, std::string del = "") {
  std::ostringstream ss;
  for (auto&& v : c) {
    if (&v != &*std::begin(c)) {
      ss << del;
    }
    ss << v;
  }
  return ss.str();
}

template <typename... Args>
std::string fmt(std::string_view format, Args... args) {
  size_t size = snprintf(nullptr, 0, format.data(), args...);
  std::vector<char> buf(size + 1);
  sprintf(buf.data(), format.data(), args...);
  return std::string(buf.data(), size);
}

}  // namespace util
