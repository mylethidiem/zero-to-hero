#include <algorithm>
#include <iostream>
#include <vector>

void lambdaDemo() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  // Basic lambda
  auto print = [](int n) { std::cout << n << " "; };

  // Lambda with capture
  int multiplier = 10;
  auto multiply = [multiplier](int n) { return n * multiplier; };

  // Generic lambda (C++14)
  auto genericLambda = [](auto a, auto b) { return a + b; };

  // Using lambdas
  std::for_each(numbers.begin(), numbers.end(), print);
  std::cout << "\n";

  std::cout << "Multiply 5 by 10: " << multiply(5) << "\n";
  std::cout << "Generic lambda: " << genericLambda(5, 3.14) << "\n";
}
