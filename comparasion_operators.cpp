#include "algexpr.hpp"

namespace algexpr {
bool operator==(const algexpr &a, const algexpr &b) {
  return (a - b).simplify().to_string() == "0";
}
} // namespace algexpr