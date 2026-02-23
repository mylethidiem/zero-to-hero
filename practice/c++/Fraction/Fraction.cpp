#include <cmath>
#include <conio.h>
#include <iostream>
#include <limits>

struct Fraction {
  int numerator = 0; // tử số
  int denominator = 0; // mẫu số
};

int UCLN(int a, int b) {
  int min = (a > b) ? a : b;
  int max = (a < b) ? a : b;

  if (max == min || max % min == 0) {
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

void Compact(Fraction &f) { // Rút gọn
  int ucln = UCLN(f.numerator, f.denominator);
  f.numerator /= ucln;
  f.denominator /= ucln;
}

Fraction Sum(Fraction f1, Fraction f2) {
  Fraction result;
  result.numerator =
      f1.numerator * f2.denominator + f1.denominator * f2.numerator;
  result.denominator = f1.denominator * f2.denominator;
  Compact(result);
  return result;
}

Fraction Subtract(Fraction f1, Fraction f2) {
  Fraction result;
  result.numerator =
      f1.numerator * f2.denominator - f1.denominator * f2.numerator;
  result.denominator = f1.denominator * f2.denominator;
  Compact(result);
  return result;
}

Fraction Multiply(Fraction f1, Fraction f2) {
  Fraction result;
  result.numerator = f1.numerator * f2.numerator;
  result.denominator = f1.denominator * f2.denominator;
  Compact(result);
  return result;
}

Fraction Divide(Fraction f1, Fraction f2) {
  Fraction result;
  result.numerator = f1.numerator * f2.denominator;
  result.denominator = f1.denominator * f2.numerator;
  Compact(result);
  return result;
}

void InputFractions(Fraction &f) {
  do {
    std::cout << "Input the numerator: ";
    std::cin >> f.numerator;
    std::cout << "";
    std::cout << "Input the demoninator: ";
    std::cin >> f.denominator;
  } while (f.numerator < 0 && f.denominator <= 0);
}

void ShowFraction(Fraction f) {
  std::cout << "Numerator: " << f.numerator << std::endl;
  std::cout << "Denominator: " << f.denominator << std::endl;
}

void ActionFractions(Fraction &f1, Fraction &f2) {
  Fraction result;
  std::cout << "Input 1st fraction: \n";
  InputFractions(f1);

  std::cout << "\nInput 2nd fraction: \n";
  InputFractions(f2);

  result = Sum(f1, f2);
  std::cout << "\nSum of 2 fractions: " << std::endl;
  ShowFraction(result);

  result = Subtract(f1, f2);
  std::cout << "\nSubtract of 2 fractions: " << std::endl;
  ShowFraction(result);

  result = Multiply(f1, f2);
  std::cout << "\nMultiply of 2 fractions: " << std::endl;
  ShowFraction(result);

  result = Divide(f1, f2);
  std::cout << "\nDivide of 2 fractions: " << std::endl;
  ShowFraction(result);
}

int main()
{
  /*
   * Fraction
   */
  Fraction f1, f2;
  ActionFractions(f1, f2);

  return 0;
}
