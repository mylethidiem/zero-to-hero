#include <iostream>
#include <memory>
#include <thread>
#include <vector>

// Add declarations for new demos
void weakPointerDemo();
void lambdaDemo();
void constexprEnumDemo();
void moveDemo();
void containersAlgorithmsDemo();
void cpp17FeaturesDemo();
void conceptsDemo();

// Add new thread demo declarations
void basicThreadDemo();
void threadWithParams();
void mutexDemo();
void conditionVariableDemo();
void threadPoolDemo();
void asyncDemo();
void promiseDemo();

int main()
{
	std::cout << "Modern C++ Research Project\n";
	std::cout << "1. OOP Examples\n";
	std::cout << "2. Pointer Examples\n";
	std::cout << "3. Threading Examples\n";
	std::cout << "  3.1 Basic Threads\n";
	std::cout << "  3.2 Thread Parameters\n";
	std::cout << "  3.3 Mutex Synchronization\n";
	std::cout << "  3.4 Condition Variables\n";
	std::cout << "  3.5 Thread Pool\n";
	std::cout << "  3.6 Async/Future\n";
	std::cout << "  3.7 Promise/Future\n";
	std::cout << "4. Template Examples\n";
	std::cout << "5. Lambda Expressions\n";
	std::cout << "6. Constexpr and Enum Class\n";
	std::cout << "7. Move Semantics\n";
	std::cout << "8. Containers and Algorithms\n";
	std::cout << "9. C++17 Features\n";
	std::cout << "10. C++20 Concepts\n";

	int choice;
	std::cout << "Enter your choice (1-10): ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		// Call OOP examples
		break;
	case 2:
		// Call Pointer examples
		break;
	case 31:
		//basicThreadDemo();
		break;
	case 32:
		//threadWithParams();
		break;
	case 33:
		//mutexDemo();
		break;
	case 34:
		//conditionVariableDemo();
		break;
	case 35:
		//threadPoolDemo();
		break;
	case 36:
		//asyncDemo();
		break;
	case 37:
		//promiseDemo();
		break;
	case 4:
		// Call Template examples
		break;
	case 5:
		//lambdaDemo();
		break;
	case 6:
		//constexprEnumDemo();
		break;
	case 7:
		//moveDemo();
		break;
	case 8:
		//containersAlgorithmsDemo();
		break;
	case 9:
		//cpp17FeaturesDemo();
		break;
	case 10:
		//conceptsDemo();
		break;
	default:
		std::cout << "Invalid choice\n";
	}

	return 0;
}