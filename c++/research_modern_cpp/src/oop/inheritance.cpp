#include <iostream>
#include <string>

class Animal
{
protected:
	std::string name;

public:
	Animal(const std::string &name) : name(name) {}
	virtual void makeSound() const = 0;
	virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
	Dog(const std::string &name) : Animal(name) {}
	void makeSound() const override
	{
		std::cout << name << " says: Woof!\n";
	}
};

class Cat : public Animal
{
public:
	Cat(const std::string &name) : Animal(name) {}
	void makeSound() const override
	{
		std::cout << name << " says: Meow!\n";
	}
};