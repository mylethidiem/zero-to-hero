#include <cmath>
#include <conio.h>
#include <iostream>
#include <unordered_set>
#include "ReadNumber.h"

/*
 * Read the number:
 * EX: 1 => One
 * 12 twelve
 * 24567 twenty four thousand five hundred sixty seven
 */

void NumberHelper::showString(std::string numberString) { std::cout << numberString; };
void NumberHelper::showNumberLower16(int number) {
    switch (number) {
    case 0: {
        showString("Zero");
    } break;
    case 1: {
        showString("One");
    } break;
    case 2: {
        showString("Two");
    } break;
    case 3: {
        showString("Three");
    } break;
    case 4: {
        showString("Four");
    } break;
    case 5: {
        showString("Five");
    } break;
    case 6: {
        showString("Six");
    } break;
    case 7: {
        showString("Seven");
    } break;
    case 8: {
        showString("Eight");
    } break;
    case 9: {
        showString("Nine");
    } break;
    case 10: {
        showString("Ten");
    } break;
    case 11: {
        showString("Eleven");
    } break;
    case 12: {
        showString("Twelve");
    } break;
    case 13: {
        showString("Thirdteen");
    } break;
    case 15: {
        showString("Fifteen");
    } break;
    }
}
void NumberHelper::showNumberLower20(int number) {
    int unit = number % 10;

    if (number < 16) {
        showNumberLower16(number);
    }
    else {
        showNumberLower16(unit);
        showString("teen");
    }
}
void NumberHelper::showNumberTwoDigitWithUnitZero(int number) {
    int dozen = number / 10;

    switch (number) {
    case 20: {
        showString("Twenty");
    } break;
    case 30: {
        showString("Thirdty");
    } break;
    case 40: {
        showString("Forty");
    }; break;
    case 50: {
        showString("Fifty");
    }; break;
    default: // 60,70,80,90
    {
        showNumberLower16(dozen);
        showString("ty");
    }
    }
}

void NumberHelper::showNumberTwoDigit(int number) {
    int dozen = number / 10;
    int unit = number % 10;
    if (number < 20) {
        showNumberLower20(number);
    }
    else {
        if (unit == 0) {
            showNumberTwoDigitWithUnitZero(number);
        }
        else {
            dozen *= 10;
            showNumberTwoDigitWithUnitZero(dozen);
            showString("-");
            showNumberLower16(unit);
        }
    }
}

void NumberHelper::showNumberThreeDigit(int number) {
    int hundred = number / 100;
    int dozen = number % 100;
    showNumberLower20(hundred);
    showString(" Hundred ");

    if (dozen != 0) {
        showNumberTwoDigit(dozen);
    }
}

void NumberHelper::showNumberFourToNineDigit(int number) {
    int firstThreeNumber = 0;
    int lastNumber = 0;
    int digit = GetNumberDigit(number);

    if (digit < 7) {
        firstThreeNumber = number / 1000;
        lastNumber = number % 1000;
    }
    else {
        firstThreeNumber = number / 1000000;
        lastNumber = number % 1000000;
    }

    int firstThreeNumberDigit = GetNumberDigit(firstThreeNumber);
    int lastNumberDigit = GetNumberDigit(lastNumber);

    if (firstThreeNumberDigit == 1) {
        showNumberLower20(firstThreeNumber);
    }
    else if (firstThreeNumberDigit == 2) {
        showNumberTwoDigit(firstThreeNumber);
    }
    else if (firstThreeNumberDigit == 3) {
        showNumberThreeDigit(firstThreeNumber);
    }

    if (digit < 7) {
        showString(" Thousand ");
    }
    else {
        showString(" Million ");
    }

    if (lastNumber == 0) {
        return;
    }

    if (lastNumberDigit == 1) {
        showNumberLower20(lastNumber);
    }
    else if (lastNumberDigit == 2) {
        showNumberTwoDigit(lastNumber);
    }
    else if (lastNumberDigit == 3) {
        showNumberThreeDigit(lastNumber);
    }
    else if (lastNumberDigit > 4) {
        showNumberFourToNineDigit(lastNumber);
    }
}

int NumberHelper::GetNumberDigit(int number)
{
    return (int)(log10(number) + 1);
}

void NumberHelper::ReadNumber(int number) {
    std::cout << "The number " << number << " is read as: ";
    // 1 digit
    if (number < 20) {
        showNumberLower20(number);
    }
    // 2 digits
    else if (GetNumberDigit(number) == 2) {
        showNumberTwoDigit(number);
    }
    // 3 digits
    else if (GetNumberDigit(number) == 3) {
        showNumberThreeDigit(number);
    }
    // 4 => 9 digits
    else if (GetNumberDigit(number) > 3 && GetNumberDigit(number) < 10) {
        showNumberFourToNineDigit(number);
    }
    else {
        // TO DO
    }
    std::cout << "" << std::endl;
}

NumberHelper::NumberHelper() {

}

int NumberHelper::InputNumberBelow10Digit()
{
    unsigned int digit;
    int number;
    do {
        std::cout << "Input the number to read: ";
        std::cin >> number;

        digit = GetNumberDigit(number);
        if (digit > 9) {
            std::cout << "Currently, we only support number having below 10 digit. "
                << std::endl;
        }
    } while (number < 0 && digit > 9);
    return number;
}

/*
 * Check Number Type
 */
 bool NumberHelper::isSymmetricalNumber(int n) {
  // 121, 1221...
  // 1221%10 reverse number => a[0..num-1] s = s + a[i] => compare s va n
  int reverseNumber = 0;
  int temp = n;
  while (n > 0) {
    reverseNumber = reverseNumber * 10 + n % 10;
    n = n / 10;
  }

  if (reverseNumber == temp) {
    return true;
  }
  return false;
}

bool NumberHelper::isSquareNumber(int n) {
  // 1,4,9...
  // i=0...[sqNum (= sqrt(n))],sqNum < n/2, compare pow(i) & n%10
  if (n == 1) {
    return true;
  }

  int i = 1;
  for (; i <= n / 2; i++) {
    if ((i * i) == n) {
      return true;
    }
  }
  return false;
}
bool NumberHelper::isSquareNumberWay2(int n) {
  // 1,4,9...
  /*
   * Compare sqrt
   */
  if (n == 1) {
    return true;
  }
  /*
   * Compare sqrt
   */
  if (sqrt((double)n) == (int)sqrt((double)n)) {
    return true;
  }

  return false;
}

bool NumberHelper::isPrimeNumber(int n) {
  // special case:1,2,3 and ,5,7,11,13,17...
  // i=0...(n-1), if n % i == 0 => not prime
  // does not care even number
  if (n == 1) {
    return false;
  }
  if (n == 2 || n == 3) {
    return true;
  }

  // int i = (n - 1) / 2;
  int i = 3;
  if (n > 3 && (n % 2) == 0) {
    return false;
  }

  for (; i <= (int)sqrt((double)n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool NumberHelper::isAscendingNumber(int n) {
  // 11, 123, 11223,...
  // remainder = n%10, n=n%10, i2 = n%10, if remainder > i2 > i3 > i4 ...true
  int remainder = n % 10;
  n = n / 10;
  while (n / 10 != 0) {
    if (remainder >= (n % 10)) // remainder > i2
    {
      remainder = n % 10;
      n = n / 10;
    } else {
      return false;
    }
  }
  return true;
}

bool NumberHelper::isDescendingNumber(int n) {
  // 11, 321, 32211,...
  // remainder = n%10, n=n%10, i2 = n%10, if remainder < i2 < i3 < i4 ...true
  int remainder = n % 10;
  while (n / 10 != 0) {
    n = n / 10;
    if (remainder <= (n % 10)) // i1 < i2
    {
      remainder = n % 10;
    } else {
      return false;
    }
  }
  return true;
}
// check number type in [a,b]
void NumberHelper::specialNumberIdentifier(int a, int b) {
  int synmetricNumberQuantity = 0, squareNumberQuantity = 0,
      primeNumberQuantity = 0;
  int synmetricNumberSum = 0, squareNumberSum = 0, primeNumberSum = 0;
  int i = 0;
  for (i = a; i <= b; i++) {
    if (isSymmetricalNumber(i) == true) {
      std::cout << "Symmetrical Number: " << i << " " << std::endl;
      synmetricNumberQuantity++;
      synmetricNumberSum += i;
    } else if (isSquareNumber(i) == true) {
      std::cout << "Square Number: " << i << " " << std::endl;
      squareNumberQuantity++;
      squareNumberSum += i;
    } else if (isPrimeNumber(i) == true) {
      std::cout << "Prime Number: " << i << " " << std::endl;
      primeNumberQuantity++;
      primeNumberSum += i;
    }
  }
  std::cout << " " << std::endl;
  std::cout << "Sum of Synmetrical Number: " << synmetricNumberSum << " "
            << std::endl;
  std::cout << "Sum of Square Number: " << squareNumberSum << " " << std::endl;
  std::cout << "Sum of Prime Number: " << primeNumberSum << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "Number of Synmetrical Number: " << synmetricNumberQuantity
            << " " << std::endl;
  std::cout << "Number of Square Number: " << squareNumberQuantity << " "
            << std::endl;
  std::cout << "Number of Prime Number: " << primeNumberQuantity << " "
            << std::endl;
}

void NumberHelper::findNumExercise3(int a, int b) {
  int i = a;
  for (; i <= b; i++) {
    int dozen = i / 10;
    int unit = i % 10;
    int multi = dozen * unit;
    int sum = 2 * (dozen + unit);

    if (multi == sum) {
      std::cout << "Number: " << i << std::endl;
    }
  }
}

/*
 * Other way: a != b
 * if a > b: a -= b
 * if b < a: b -= a
 * if a == b: return a
 */
int NumberHelper::UCLN(int a, int b) {
  int min = (a > b) ? a : b;
  int max = (a < b) ? a : b;

  if (max == min) {
    return max;
  } else if (max % min == 0) {
    return min;
  } else {
    int i = min / 2;
    for (; i > 0; i--) {
      if ((a % i == 0) && (b % i == 0)) {
        return i;
      }
    }
  }
  return 1;
}

void NumberHelper::Fibonacci(unsigned long long int n) {
  unsigned long long int a0 = 1;
  unsigned long long int a1 = 1, i = 0;

  std::cout << a0 << " " << a1;
  while (a0 + a1 <= n) {
    unsigned long long int c = a1 + a0;
    a0 = a1;
    a1 = c;
    std::cout << " " << a1;
  }
}

bool NumberHelper::isPerfect(int n)
{
    int sumOfDivisors = 1;
    for (int i = 2; i <= (int)n / 2; i++)
    {
        if (n % i == 0)
        {
            sumOfDivisors += i;
        }
    }
    if (sumOfDivisors == n)
        return true;
    return false;
}

bool NumberHelper::isArmstrong(int n)
{
    int sum = 0, temp = n;
    int digit = GetNumberDigit(n);
    while (temp % 10 != 0)
    {
        sum += (int) pow(temp % 10, 3.0);
        temp /= 10;
    }
    if (sum == n)
        return true;
    return false;
}

bool NumberHelper::isPalindrome(int n)
{
    return isSymmetricalNumber(n);
}

bool NumberHelper::isHarshad(int n)
{
    int sumOfNumbers = 1, temp = n;
    while (temp % 10 == 0)
    {
        sumOfNumbers += temp % 10;
        temp /= 10;
    }
    if (n % sumOfNumbers == 0)
        return true;
    return false;
}

bool NumberHelper::isHappy(int n)
{
    std::unordered_set<int> alreadyAppearNumber;
    while (n != 1)
    {
        if (alreadyAppearNumber.find(n) != alreadyAppearNumber.end()) {
            return false;
        }
        // Save current n
        alreadyAppearNumber.insert(n);

        // Sum of square of each digits
        int sum = 0;
        while (n != 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    return true;
}

int main()
{
    /*
     * Read number
     */
    NumberHelper numberHelper = NumberHelper();
    while (true)
    {
        std::cout << "\n=========================================\n";
        std::cout << "Press any key to continue or ESC to exit." << std::endl;
        int key = _getch();
        if (key == 27) { // ESC
            break;
        }
        else
        {
            int number = numberHelper.InputNumberBelow10Digit();
            numberHelper.ReadNumber(number);

            std::cout << "isSymmetricalNumber: " << numberHelper.isSymmetricalNumber(number) << " " << std::endl;
            std::cout << "isSquareNumber: " << numberHelper.isSquareNumber(number) << " " << std::endl;
            std::cout << "isPerfect: " << numberHelper.isPerfect(number) << " " << std::endl;
            std::cout << "isArmstrong: " << numberHelper.isArmstrong(number) << " " << std::endl;
            std::cout << "isPalindrome: " << numberHelper.isPalindrome(number) << " " << std::endl;
            std::cout << "isHarshad: " << numberHelper.isHarshad(number) << " " << std::endl;
            std::cout << "isHappy: " << numberHelper.isHappy(number) << " " << std::endl;
            std::cout << "isPrimeNumber: " << numberHelper.isPrimeNumber(number) << " " << std::endl;
            std::cout << "isAscendingNumber: " << numberHelper.isAscendingNumber(number) << " " << std::endl;
            std::cout << "isDescendingNumber: " << numberHelper.isDescendingNumber(number) << " " << std::endl;

            std::cout << "Fibonacci list from 1 to " << number  << " : " << std::endl;
            numberHelper.Fibonacci(number);
            std::cout << std::endl;
        }
    }

  // input 2
  int a = 0, b = 0;
  do {
    std::cout << " " << std::endl;
    std::cout << "Input number a: " << std::endl;
    std::cin >> a;
    std::cout << "Input number b: " << std::endl;
    std::cin >> b;
    std::cout << " " << std::endl;
  } while (b < a);
  numberHelper.specialNumberIdentifier(a, b);

  // output 3
  do {
    std::cout << " " << std::endl;
    std::cout << "Input number a: " << std::endl;
    std::cin >> a;
    std::cout << "Input number b: " << std::endl;
    std::cin >> b;
    std::cout << " " << std::endl;
  } while ((a < 10 && a > 99) || (b < 10 && b > 99));
  numberHelper.findNumExercise3(a, b);

  // output 4
  std::cout << "UCLN is:  " << a << " & " << b << ": " << numberHelper.UCLN(a, b) << std::endl;

    return 0;
}
