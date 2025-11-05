#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

std::mutex printMutex;

// 1. Basic Thread Creation
void basicThreadDemo() {
  auto threadFunction = []() {
    std::lock_guard<std::mutex> lock(printMutex);
    std::cout << "Thread " << std::this_thread::get_id() << " running\n";
  };

  std::thread t1(threadFunction);
  std::thread t2(threadFunction);

  t1.join();
  t2.join();
}

// 2. Thread with Parameters
void threadWithParams() {
  auto paramThread = [](int id, std::string message) {
    std::lock_guard<std::mutex> lock(printMutex);
    std::cout << "Thread " << id << ": " << message << "\n";
  };

  std::thread t1(paramThread, 1, "Hello");
  std::thread t2(paramThread, 2, "World");

  t1.join();
  t2.join();
}

// 3. Mutex Synchronization
class Counter {
  mutable std::mutex mutex;
  int value = 0;

public:
  void increment() {
    std::lock_guard<std::mutex> lock(mutex);
    ++value;
  }

  int get() const {
    std::lock_guard<std::mutex> lock(mutex);
    return value;
  }
};

void mutexDemo() {
  Counter counter;
  std::vector<std::thread> threads;

  for (int i = 0; i < 10; ++i) {
    threads.emplace_back([&counter]() {
      for (int j = 0; j < 1000; ++j) {
        counter.increment();
      }
    });
  }

  for (auto &t : threads) {
    t.join();
  }

  std::cout << "Final counter value: " << counter.get() << "\n";
}
