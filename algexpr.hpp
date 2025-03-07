#pragma once

#include <algorithm>
#include <arithmetica.hpp>
#include <string>
#include <unordered_map>
#include <vector>

namespace algexpr {
typedef arithmetica::Fraction frac;
class algexpr {
private:
  bool has_non_number(const std::string &s) const;
  std::string add_parentheses_if_needed(const std::string &s,
                                        const std::string &f) const;
  std::string stringify_function_call(const std::string &f,
                                      const std::string &l,
                                      const std::string &r) const;
  bool is_opening_bracket(const char &c) const;
  bool is_closing_bracket(const char &c) const;
  int find_sign(const std::string &s, const char &c, bool backward,
                bool exclude_first = true) const;
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

  std::string to_string() const;

  bool is_numeric();
  bool is_natural_number(); // [0,1,...,inf)

  algexpr deep_copy() const;
  std::vector<algexpr> decompose_into_terms();
  std::vector<algexpr> decompose_into_products();

  algexpr distribute_exponent_over_product();
  algexpr simplify_term(bool bring_coeff_to_front = true); // single product
  algexpr distribute_exponent_over_sum();                  // expands (...)^n
  algexpr evaluate_multiplication(); // you need func == "*"
  algexpr combine_like_terms();

  void simplify_in_place(); // simplifies, using all the functions above
  algexpr simplify();       // simplifies, using all the functions above
};

algexpr operator+(const algexpr &a, const algexpr &b);
algexpr operator-(const algexpr &a, const algexpr &b);
algexpr operator*(const algexpr &a, const algexpr &b);
algexpr operator/(const algexpr &a, const algexpr &b);
algexpr operator^(const algexpr &a, const algexpr &b);
bool operator==(const algexpr &a, const algexpr &b);
} // namespace algexpr