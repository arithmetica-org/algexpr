#include "algexpr.hpp"

namespace algexpr {
std::vector<algexpr> algexpr::decompose_into_products() {
  std::vector<algexpr> ans;
  if (func == "*") {
    for (auto &i : l->decompose_into_products()) {
      ans.push_back(i.deep_copy());
    }
    for (auto &i : r->decompose_into_products()) {
      ans.push_back(i.deep_copy());
    }
    return ans;
  }
  ans.push_back(deep_copy());
  return ans;
}
} // namespace algexpr