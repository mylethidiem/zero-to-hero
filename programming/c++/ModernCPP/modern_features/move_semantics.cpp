#include <iostream>
#include <string>
#include <vector>

class MovableClass {
  std::vector<int> data;

public:
  // Constructor
  MovableClass(size_t size) : data(size) {}

  // Move constructor
  MovableClass(MovableClass &&other) noexcept : data(std::move(other.data)) {
    std::cout << "Move constructor called\n";
  }

  // Move assignment
  MovableClass &operator=(MovableClass &&other) noexcept {
    if (this != &other) {
      data = std::move(other.data);
      std::cout << "Move assignment called\n";
    }
    return *this;
  }
};

void moveDemo() {
  MovableClass obj1(1000);
  MovableClass obj2 = std::move(obj1);
}
