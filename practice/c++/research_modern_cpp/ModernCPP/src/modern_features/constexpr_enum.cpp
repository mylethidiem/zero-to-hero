#include <iostream>

// Constexpr function
constexpr int fibonacci(int n) {
  if (n <= 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// Smart enum
enum class Color { Red, Green, Blue };

enum class Status { Success, Failure, Pending };

void constexprEnumDemo() {
  // Constexpr examples
  constexpr int fib10 = fibonacci(10);
  std::cout << "10th Fibonacci number: " << fib10 << "\n";

  // Enum class examples
  Color c = Color::Red;
  Status s = Status::Success;

  // Type-safe comparison
  // This won't compile: if (c == s)
  if (c == Color::Red) {
    std::cout << "Color is red\n";
  }
}
