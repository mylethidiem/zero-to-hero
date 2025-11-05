#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

// 4. Condition Variable Example
class ThreadSafeQueue {
  std::queue<int> queue;
  mutable std::mutex mutex;
  std::condition_variable cond;

public:
  void push(int value) {
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(value);
    cond.notify_one();
  }

  int pop() {
    std::unique_lock<std::mutex> lock(mutex);
    cond.wait(lock, [this] { return !queue.empty(); });

    int value = queue.front();
    queue.pop();
    return value;
  }
};

void conditionVariableDemo() {
  ThreadSafeQueue queue;

  // Producer thread
  std::thread producer([&queue]() {
    for (int i = 0; i < 5; ++i) {
      std::cout << "Producing: " << i << "\n";
      queue.push(i);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  });

  // Consumer thread
  std::thread consumer([&queue]() {
    for (int i = 0; i < 5; ++i) {
      int value = queue.pop();
      std::cout << "Consuming: " << value << "\n";
    }
  });

  producer.join();
  consumer.join();
}
