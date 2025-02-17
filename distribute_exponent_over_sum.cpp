#include "algexpr.hpp"

namespace algexpr {
algexpr algexpr::distribute_exponent_over_sum() {
  if (func != "^") {
    return *this;
  }
  if (l->is_numeric() and l->coeff.to_string() == "1") {
    algexpr ans;
    ans.coeff = "1";
    return ans;
  }
  if (!r->is_natural_number()) {
    return *this;
  }
  if (l->is_numeric()) {
    frac constant("1");
    for (frac i = frac("0"); !(i == r->coeff); i = i + frac("1")) {
      constant = constant * l->coeff;
    }
    algexpr ans;
    ans.coeff = constant;
    return ans;
  }
  algexpr ans("1");
  bool modified_ans = false;
  for (frac i = frac("0"); !(i == r->coeff); i = i + frac("1")) {
    if (!modified_ans) {
      modified_ans = true;
      ans = *l;
    } else {
      ans = (ans * *l).evaluate_multiplication();
    }
    ans = ans.combine_like_terms();
  }
  return ans;
}
} // namespace algexpr