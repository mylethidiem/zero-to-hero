#include <iostream>
#include <tuple>
#include <filesystem>
#include <optional>
#include <variant>

namespace fs = std::filesystem;

void cpp17FeaturesDemo()
{
	// Structured bindings
	std::tuple<int, std::string, double> tuple{1, "Hello", 3.14};
	auto [id, message, value] = tuple;

	// Filesystem
	fs::path currentPath = fs::current_path();
	std::cout << "Current path: " << currentPath << "\n";

	// Optional
	std::optional<int> opt = std::nullopt;
	opt = 42;
	if (opt.has_value())
	{
		std::cout << "Optional value: " << *opt << "\n";
	}

	// Variant
	std::variant<int, std::string, double> var = "Hello";
	std::cout << "Variant holds: " << std::get<std::string>(var) << "\n";
}