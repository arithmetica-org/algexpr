#include "algexpr.hpp"

namespace algexpr {
bool operator==(const algexpr &a, const algexpr &b) {
  // this is NOT how you should be doing it, but i am temporarily cuz i havent
  // coded simplification yet

  // ideally, you'd wanna create algexpr(a-b).simplify() and check if THIS is
  // equal to 0. but for now, we're just gonna do a.to_string() == b.to_string()

  return a.to_string() == b.to_string();
}
} // namespace algexpr