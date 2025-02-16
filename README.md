# Algexpr Attempt #3
### _It'll work this time, right?_

## Usage
```cpp
#include <algexpr.hpp>
#include <iostream>
int main() {
  while (true) {
    std::cout << "enter expr: ";
    std::string s;
    std::getline(std::cin, s);

    algexpr::algexpr expr(s);
    std::cout << expr.to_string() << '\n';

    auto terms = expr.decompose_into_terms();
    std::cout << terms.size() << " terms\n";
    for (auto &i : terms) {
      std::cout << i.to_string() << '\n';
    }
  }
}
```

## Bugs
**Several**