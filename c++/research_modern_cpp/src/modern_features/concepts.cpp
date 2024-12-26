#include <iostream>
#include <concepts>

// Basic concept
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

// Complex concept
template <typename T>
concept Sortable = requires(T a, T b) {
	{ a < b } -> std::convertible_to<bool>;
	{ a > b } -> std::convertible_to<bool>;
};

// Function using concept
template <Numeric T>
T add(T a, T b)
{
	return a + b;
}

// Function using complex concept
template <Sortable T>
void sort_two(T &a, T &b)
{
	if (b < a)
		std::swap(a, b);
}

void conceptsDemo()
{
	std::cout << "Add integers: " << add(5, 3) << "\n";
	std::cout << "Add doubles: " << add(3.14, 2.72) << "\n";

	int x = 5, y = 3;
	sort_two(x, y);
	std::cout << "Sorted numbers: " << x << ", " << y << "\n";
}