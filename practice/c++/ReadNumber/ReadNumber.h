#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include <string>

class Number
{
public:
	int m_value = 0;
	unsigned int m_digit = 0;

	Number();
	void InputNumber();
	void ReadNumber();

private:
	void showString(std::string numberString);
	void showNumberLower16(int number);
	void showNumberLower20(int number);
	void showNumberTwoDigitWithUnitZero(int number);
	void showNumberTwoDigit(int number);
	void showNumberThreeDigit(int number);
	void showNumberFourToNineDigit(int number);

	int GetNumberDigit(int number);
};
#endif