#include "algexpr.hpp"

namespace algexpr {

std::vector<algexpr> algexpr::decompose_into_terms() {
  std::vector<algexpr> ans;
  if (func == "+") {
    for (auto &i : l->decompose_into_terms()) {
      ans.push_back(i.deep_copy());
    }
    for (auto &i : r->decompose_into_terms()) {
      ans.push_back(i.deep_copy());
    }
    return ans;
  }
  if (func == "-") {
    for (auto &i : l->decompose_into_terms()) {
      ans.push_back(i.deep_copy());
    }
    for (auto &i : r->decompose_into_terms()) {
      algexpr e;
      e.func = '*';
      e.l = new algexpr("-1");
      e.r = new algexpr(i.deep_copy());
      ans.push_back(e);
    }
    return ans;
  }
  ans.push_back(*this);
  return ans;
}

} // namespace algexpr