#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <numeric>

// 7. Async/Future Example
int calculateSum(const std::vector<int> &vec)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return std::accumulate(vec.begin(), vec.end(), 0);
}

void asyncDemo()
{
	std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// Launch async calculation
	auto future = std::async(std::launch::async, calculateSum, numbers);

	std::cout << "Calculating sum...\n";

	// Get result when ready
	int sum = future.get();
	std::cout << "Sum: " << sum << "\n";
}

// 8. Promise and Future Example
void promiseDemo()
{
	std::promise<std::string> promise;
	std::future<std::string> future = promise.get_future();

	std::thread producer([&promise]()
						 {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        promise.set_value("Hello from producer thread!"); });

	std::thread consumer([&future]()
						 {
        std::cout << "Waiting for value...\n";
        std::cout << "Received: " << future.get() << "\n"; });

	producer.join();
	consumer.join();
}