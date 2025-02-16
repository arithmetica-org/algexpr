#include "algexpr.hpp"

namespace algexpr {
std::string algexpr::add_parentheses_if_needed(const std::string &s) const {
  if (s.length() == 1) {
    return s;
  }
  bool has_non_number = false;
  for (auto &i : s) {
    has_non_number = has_non_number or i < '0' or i > '9';
  }
  if (!has_non_number) {
    return s;
  }
  return "(" + s + ")";
}

std::string algexpr::stringify_function_call(const std::string &f,
                                             const std::string &l,
                                             const std::string &r) const {
  if (f == "+" or f == "-" or f == "*" or f == "/" or f == "^") {
    std::string ans = add_parentheses_if_needed(l);
    if (f == "+" or f == "-" or f == "*") {
      ans += " ";
    }
    ans += f;
    if (f == "+" or f == "-" or f == "*") {
      ans += " ";
    }
    ans += add_parentheses_if_needed(r);
    return ans;
  }
  // unary functions
  if (l.empty()) {
    return f + "(" + r + ")";
  }
  if (r.empty()) {
    return f + "(" + l + ")";
  }

  return f + "(" + l + ", " + r + ")";
}

std::string algexpr::to_string() const {
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
  }
  if (r != nullptr) {
    right = r->to_string();
  }
  return stringify_function_call(func, left, right);
}
} // namespace algexpr