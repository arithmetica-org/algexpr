#pragma once

#include <algorithm>
#include <arithmetica.hpp>
#include <string>
#include <vector>

namespace algexpr {
typedef arithmetica::Fraction frac;
class algexpr {
private:
  std::string stringify_function_call(const std::string &f,
                                      const std::string &l,
                                      const std::string &r);
  bool is_opening_bracket(const char &c);
  bool is_closing_bracket(const char &c);
  int find_sign(const std::string &s, const char &c, bool backward);
  int closing_bracket(const std::string &s, int st);
  std::pair<int, int> get_first_bracket_pair(const std::string &s);
  bool is_function(const std::string &s);
  int find_letter(const std::string &s);
  int variable_end(const std::string &s, int st);

public:
  algexpr *l;
  algexpr *r;

  // funtion applied on children
  std::string func;

  // leaf (one variable active per leaf)
  frac coeff;
  std::string variable;

  algexpr();
  algexpr(const algexpr &other);
  algexpr(std::string s);

  std::string to_string();

  algexpr deep_copy();
  std::vector<algexpr> decompose_into_terms();

  // todo
  void canonicalize_products();
};

algexpr operator/(algexpr a, algexpr b);
} // namespace algexpr