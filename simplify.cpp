#include "algexpr.hpp"

namespace algexpr {
algexpr algexpr::simplify() {
  if (l != nullptr) {
    l = new algexpr(l->simplify());
  }
  if (r != nullptr) {
    r = new algexpr(r->simplify());
  }
  algexpr ans = *this;
  ans = ans.distribute_exponent_over_sum();
  if (ans.l != nullptr) {
    ans.l = new algexpr(ans.l->simplify());
  }
  if (ans.r != nullptr) {
    ans.r = new algexpr(ans.r->simplify());
  }
  ans = ans.evaluate_multiplication();
  if (ans.l != nullptr) {
    ans.l = new algexpr(ans.l->simplify());
  }
  if (ans.r != nullptr) {
    ans.r = new algexpr(ans.r->simplify());
  }
  ans = ans.combine_like_terms();
  if (ans.l != nullptr) {
    ans.l = new algexpr(ans.l->simplify());
  }
  if (ans.r != nullptr) {
    ans.r = new algexpr(ans.r->simplify());
  }
  return ans;
}
} // namespace algexpr