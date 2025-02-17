#include "algexpr.hpp"
#include <iostream>
int main() {
  // 1/2k*x*x is an edge case
  // also c _{earth} is an edge case (note the space between the thing and the
  // _): to fix remove spaces behind _ (which are not in brackets) maybe?

  // todo: add explicit multiplcation sign behind []/[] and []^[]

  while (true) {
    std::cout << "enter expr: ";
    std::string s;
    std::getline(std::cin, s);

    algexpr::algexpr expr(s);
    std::cout << expr.simplify().to_string() << '\n';
  }

  algexpr::algexpr expr("x^(-1)*x");
  expr = expr.simplify_term();
  std::cout << expr.to_string() << '\n';
}