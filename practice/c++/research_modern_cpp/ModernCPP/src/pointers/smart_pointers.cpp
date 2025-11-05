#include <iostream>
#include <memory>

class Resource {
public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
  void use() { std::cout << "Resource being used\n"; }
};

void smartPointerDemo() {
  // Unique pointer example
  std::unique_ptr<Resource> uniqueRes = std::make_unique<Resource>();
  uniqueRes->use();

  // Shared pointer example
  std::shared_ptr<Resource> sharedRes1 = std::make_shared<Resource>();
  {
    auto sharedRes2 = sharedRes1; // Reference count = 2
    std::cout << "Shared count: " << sharedRes1.use_count() << "\n";
  } // Reference count = 1
  std::cout << "Shared count: " << sharedRes1.use_count() << "\n";
}

void weakPointerDemo() {
  // Create shared_ptr
  auto sharedResource = std::make_shared<Resource>();

  // Create weak_ptr from shared_ptr
  std::weak_ptr<Resource> weakResource = sharedResource;

  std::cout << "Weak ptr expired? " << weakResource.expired() << "\n";

  if (auto temp = weakResource.lock()) {
    std::cout << "Resource still alive, using it\n";
    temp->use();
  }

  // Reset shared_ptr
  sharedResource.reset();

  std::cout << "After reset - Weak ptr expired? " << weakResource.expired()
            << "\n";
}
