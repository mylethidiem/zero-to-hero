#include <cmath>
#include <conio.h>
#include <iostream>
#include <limits>

struct Fraction {
  int numerator = 0;
  int denominator = 0;
};

int UCLN(int a, int b) {
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

void Compact(Fraction &f) {
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
    std::cout << "" << std::endl;
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
  InputFractions(f1);
  InputFractions(f2);

  result = Sum(f1, f2);
  std::cout << "Sum of 2 fractions: " << std::endl;
  ShowFraction(result);

  result = Subtract(f1, f2);
  std::cout << "Subtract of 2 fractions: " << std::endl;
  ShowFraction(result);

  result = Multiply(f1, f2);
  std::cout << "Multiply of 2 fractions: " << std::endl;
  ShowFraction(result);

  result = Divide(f1, f2);
  std::cout << "Divide of 2 fractions: " << std::endl;
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
