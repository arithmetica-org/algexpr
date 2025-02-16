#include "algexpr.hpp"

namespace algexpr {
void algexpr::simplify_in_place() {
  if (l != nullptr) {
    l = new algexpr(l->simplify());
  }
  if (r != nullptr) {
    r = new algexpr(r->simplify());
  }
  if (func == "^") {
    *this = std::move(distribute_exponent_over_sum());
    *this = std::move(distribute_exponent_over_product());
  } else if (func == "*") {
    *this = std::move(evaluate_multiplication());
    *this = std::move(combine_like_terms());
  } else {
    *this = std::move(combine_like_terms());
  }
}

algexpr algexpr::simplify() {
  algexpr ans = std::move(this->deep_copy());
  ans.simplify_in_place();
  return ans;
}
} // namespace algexpr