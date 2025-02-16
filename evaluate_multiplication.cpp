#include "algexpr.hpp"

namespace algexpr {
algexpr algexpr::evaluate_multiplication() {
  if (func != "*") {
    return *this;
  }
  auto a = l->decompose_into_terms();
  auto b = r->decompose_into_terms();
  if (a.size() == 1 and b.size() == 1) {
    return (a[0] * b[0]).simplify_term(false);
  }
  algexpr ans("0");
  bool ans_updated = false;
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      if (!ans_updated) {
        ans_updated = true;
        ans = (a[i] * b[j]).evaluate_multiplication();
      } else {
        ans = ans + (a[i] * b[j]).evaluate_multiplication();
      }
    }
  }
  return ans;
}
} // namespace algexpr