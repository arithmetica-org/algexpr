#include "algexpr.hpp"

namespace algexpr {
// (uv)^n ==> u^n*v^n
algexpr algexpr::distribute_exponent_over_product() {
  bool ans_given_value = false;
  algexpr ans("1");
  for (auto &i : decompose_into_products()) {
    if (i.func != "^") {
      if (!ans_given_value) {
        ans_given_value = true;
        ans = i;
      } else {
        ans = ans * i;
      }
      continue;
    }
    auto terms = i.l->decompose_into_products();
    if (terms.size() == 1) {
      if (!ans_given_value) {
        ans_given_value = true;
        ans = i;
      } else {
        ans = ans * i;
      }
      continue;
    }
    for (auto &term : terms) {
      if (!ans_given_value) {
        ans_given_value = true;
        ans = (term ^ *i.r);
      } else {
        ans = ans * (term ^ *i.r);
      }
    }
  }
  return ans;
}
} // namespace algexpr