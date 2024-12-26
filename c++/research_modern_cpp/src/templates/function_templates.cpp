#include <iostream>
#include <type_traits>

// Function template
template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

// Class template
template <typename T>
class Container
{
	T data;

public:
	Container(T value) : data(value) {}
	T getValue() const { return data; }
	void setValue(T value) { data = value; }
};

void templateDemo()
{
	// Function template usage
	std::cout << "Max of 10 and 20: " << max(10, 20) << "\n";
	std::cout << "Max of 3.14 and 2.72: " << max(3.14, 2.72) << "\n";

	// Class template usage
	Container<int> intContainer(42);
	Container<std::string> strContainer("Hello");

	std::cout << "Int container: " << intContainer.getValue() << "\n";
	std::cout << "String container: " << strContainer.getValue() << "\n";
}