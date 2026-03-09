#include <cmath>
#include <iostream>

void InputNumber(int &n) {
  do {
    std::cout << "Input number n: ";
    std::cin >> n;
  } while (n <= 0);
}

/**
 * @brief Bài 48: Tính S(n)=√(2+√(2+√(2+⋯√(2+√2) ) ) ) có n dấu căn
 *
 * @return int
 */
double SqrtNRadicalSignWith2(int n) {
  double sqrtResult = sqrt(2.0f), sum = 0;
  int i;
  for (i = 2; i <= n; i++) {
    sum = 2 + sqrtResult;
    sqrtResult = sqrt(sum);
  }
  return sqrtResult;
}

/**
 * @brief Bài 49: Tính S(n)= √(n+√(n-1+√(n-2+⋯√(2+√1) ) ) ) có n dấu căn.
 *
 * @return int
 */
double SqrtNRadicalSignWithN(int n) {
  double sqrtResult = sqrt(1), sum = 0;
  int i;
  for (i = 2; i <= n; i++) {
    sum = i + sqrtResult;
    sqrtResult = sqrt(sum);
  }
  return sqrtResult;
}

/**
 * @brief Bài 50: Tính S(n)= √(1+√(2+√(3+⋯√(n-1+√n) ) ) ) có n dấu căn.
 *
 * @return int
 */
double SqrtNRadicalSignWithN2(int n) {
  double sqrtResult = sqrt((double)n), sum;
  int i;
  for (i = n - 1; i >= 1; i--) {
    sum = i + sqrtResult;
    sqrtResult = sqrt(sum);
  }
  return sqrtResult;
}

/**
 * @brief Bài 51: Tính S(n)=√(n!+√((n-1)!+√((n-2)!+⋯+√(2!+√1!) ) ) ) có n dấu
 * căn.
 *
 * @return int
 */
int Factorial(int n) {
  int result = 1, i;
  for (i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

double SqrtNRadicalSignWithNFactorial(int n) {
  double sqrtResult = 1, i, sum = 0;
  for (i = 2; i <= n; i++) {
    sum = (double)Factorial(i) + sqrt((double)sqrtResult);
    sqrtResult = sqrt(sum);
  }
  return sqrtResult;
}

int main() {
  int n;
  std::cout << "Input n: " << std::endl;
  InputNumber(n);

  std::cout << "SqrtNRadicalSignWith2: " << SqrtNRadicalSignWith2(n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "SqrtNRadicalSignWithN: " << SqrtNRadicalSignWithN(n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "SqrtNRadicalSignWithN2: " << SqrtNRadicalSignWithN2(n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "SqrtNRadicalSignWithNFactorial: "
            << SqrtNRadicalSignWithNFactorial(n) << std::endl;
  std::cout << "" << std::endl;

  return 0;
}
