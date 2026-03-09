#ifndef NUMBER_HELPER_H
#define NUMBER_HELPER_H
#include <iostream>
#include <string>

class NumberHelper
{
public:
	NumberHelper();
	int InputNumberBelow10Digit();
	long long int InputNumber();
	void ReadNumber(int number);
	std::string ReadNumberAdvance(long long int number);
	std::string readThreeDigitsEN(int n);

	/*
 * Check Number Type
 * | Tên hàm         | Định nghĩa ngắn gọn                                         | Ví dụ                                   |
 * | --------------- | ----------------------------------------------------------- | --------------------------------------- |
 * | isPerfectSquare | Kiểm tra số chính phương (có căn bậc 2 là số nguyên)        | 16 (4^2), không phải 15                  |
 * | isFibonacci     | Kiểm tra số thuộc dãy Fibonacci (0,1,1,2,3,5,8,13,...)      | 8 (Fib), không phải 7                   |
 * | isPerfect       | Số hoàn thiện (bằng tổng ước số dương thực sự của nó)       | 6 (=1+2+3), 28 (=1+2+4+7+14)​            |
 * | isArmstrong     | Số Armstrong (tổng lũy thừa các chữ số = chính số đó)       | 153 (=1^3+5^3+3^3), 370                    |
 * | isSymmetrical   | Số đối xứng (đọc xuôi/ngược giống nhau)                     | 121, 1331, không phải 123​				 |
 * | isPrime         | Số nguyên tố (>1, chỉ chia hết cho 1 và chính nó)           | 7, 11, không phải 9					 |
 * | isAscending     | Các chữ số tăng dần từ trái sang phải (không lặp)           | 123, 135, không phải 132                |
 * | isDescending    | Các chữ số giảm dần từ trái sang phải (không lặp)           | 321, 987, không phải 329                |
 * | isPalindrome    | Số đối xứng (tương tự symmetrical, kiểm tra chuỗi chữ số)   | 1221, không phải 1234                   |
 * | isHarshad       | Số Harshad (chia hết cho tổng chữ số của nó)                | 18 (=1+8, 18÷9=2), không phải 19        |
 * | isHappy         | Số hạnh phúc (lặp bình phương chữ số đến 1)                 | 7 (7→49→97→130→10→1), 4 isUnHappy       |
 */

	bool isSymmetricalNumber(int n);
	bool isSquareNumber(int n);
	bool isSquareNumberWay2(int n);
	bool isPerfect(int n);
	bool isArmstrong(int n);
	bool isPalindrome(int n);
	bool isHarshad(int n);
	bool isHappy(int n);
	bool isPrimeNumber(int n);
	bool isAscendingNumber(int n);
	bool isDescendingNumber(int n);
	void specialNumberIdentifier(int a, int b);
	void findNumExercise3(int a, int b);
	int UCLN(int a, int b);
	void Fibonacci(unsigned long long int n);

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