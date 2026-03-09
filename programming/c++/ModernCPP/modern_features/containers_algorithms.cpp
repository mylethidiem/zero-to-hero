#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

void containersAlgorithmsDemo() {
  // Vector
  std::vector<int> vec = {5, 2, 8, 1, 9};
  std::sort(vec.begin(), vec.end());

  // Map
  std::map<std::string, int> orderedMap;
  orderedMap["one"] = 1;
  orderedMap["two"] = 2;

  // Unordered map
  std::unordered_map<std::string, int> hashMap;
  hashMap["three"] = 3;

  // Algorithms
  auto it = std::find(vec.begin(), vec.end(), 8);
  if (it != vec.end()) {
    std::cout << "Found 8 at position: " << std::distance(vec.begin(), it)
              << "\n";
  }
}
