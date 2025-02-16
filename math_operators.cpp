#include "algexpr.hpp"

namespace algexpr {
algexpr operator+(const algexpr &a, const algexpr &b) {
  algexpr ans;
  ans.func = "+";
  ans.l = new algexpr(a.deep_copy());
  ans.r = new algexpr(b.deep_copy());
  return ans;
}

algexpr operator-(const algexpr &a, const algexpr &b) {
  algexpr ans;
  ans.func = "-";
  ans.l = new algexpr(a.deep_copy());
  ans.r = new algexpr(b.deep_copy());
  return ans;
}

algexpr operator*(const algexpr &a, const algexpr &b) {
  algexpr ans;
  ans.func = "*";
  ans.l = new algexpr(a.deep_copy());
  ans.r = new algexpr(b.deep_copy());
  return ans;
}

algexpr operator/(const algexpr &a, const algexpr &b) {
  algexpr ans;
  ans.func = "/";
  ans.l = new algexpr(a.deep_copy());
  ans.r = new algexpr(b.deep_copy());
  return ans;
}

algexpr operator^(const algexpr &a, const algexpr &b) {
  algexpr ans;
  ans.func = "^";
  ans.l = new algexpr(a.deep_copy());
  ans.r = new algexpr(b.deep_copy());
  return ans;
}
} // namespace algexpr