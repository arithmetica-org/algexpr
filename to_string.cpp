#include "algexpr.hpp"

namespace algexpr {
std::string algexpr::stringify_function_call(const std::string &f,
                                             const std::string &l,
                                             const std::string &r) {
  // if (f == "+" or f == "-" or f == "*" or f == "/" or f == "^") {
  //   return l + " " + f + " " + r;
  // }
  // unary functions
  if (l.empty()) {
    return f + "(" + r + ")";
  }
  if (r.empty()) {
    return f + "(" + l + ")";
  }

  return f + "(" + l + ", " + r + ")";
}

std::string algexpr::to_string() {
  if (l == nullptr and r == nullptr) {
    std::string s = coeff.to_string();
    if (s == "1" and !variable.empty()) {
      s.clear();
    }
    return s + variable;
  }
  std::string left, right;
  if (l != nullptr) {
    left = l->to_string();
    cout << "" // DEBUGUWU
  }
  if (r != nullptr) {
    right = r->to_string();
  }
  return stringify_function_call(func, left, right);
}
} // namespace algexpr