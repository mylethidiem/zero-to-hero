#include <iostream>

void InputNumber(int &n) {
  do {
    std::cout << "Input number n: ";
    std::cin >> n;
  } while (n <= 0);
}

void InputNumber(double &x) {
  do {
    std::cout << "Input number x: ";
    std::cin >> x;
  } while (x <= 0);
}

int Factorial(int n) {
  int multi = 1, i;
  for (i = 1; i <= n; i++) {
    multi *= i;
  }
  return multi;
}
/**
 * @brief Bài 19:   Tính S(n)=1/2+1/4+...+1/2n .
 *
 * @return double
 */
double S1Divide2N(int n) {
  double sum = 0, i;
  for (i = 1; i <= n; i++) {
    sum += (double)1 / (2 * i);
  }
  return sum;
}

/**
 * @brief Bài 20:   Tính S(n)=1+1/3+1/5+...+1/(2n+1) .
 *
 * @return double
 */
double S1Divide2NAdd1(int n) {
  double sum = 0, i;
  for (i = 0; i <= n; i++) {
    sum += (double)1 / (2 * i + 1);
  }
  return sum;
}

/**
 * @brief Bài 21:   Tính S(n)=1/(1*2)+1/(2*3)+...+1/(n*(n+1)) .
 *
 * @return double
 */
double S1DivideNMultiNAdd1(int n) {
  double sum = 0, i;
  for (i = 1; i <= n; i++) {
    sum += (double)1 / (i * (i + 1));
  }
  return sum;
}

/**
 * @brief Bài 22:   Tính S(n)=1/2+2/3+3/4+...+n/(n+1) .
 *
 * @return double
 */
double SNDivideNAdd1(int n) {
  double sum = 0;
  int i;
  for (i = 1; i <= n; i++) {
    sum += (double)i / (i + 1);
  }
  return sum;
}

/**
 * @brief Bài 23:   Tính S(n)=1/2+3/4+5/6+...+(2n+1)/(2n+2) .
 *
 * @return double
 */
double S2NAdd1Divide2MultiNAdd1(int n) {
  double sum = 0;
  int i;
  for (i = 0; i <= n; i++) {
    sum += (double)(2 * i + 1) / (2 * i + 2);
  }
  return sum;
}

/**
 * @brief Bài 24:   Tính T(x,n)=x^n .
 *
 * @return double
 */
double TXPowN(double x, int n) {
  double multi = 1.0f;
  int i;

  for (i = 1; i <= n; i++) {
    multi *= x;
  }
  return multi;
}

/**
 * @brief Bài 25:   Tính S(n)=1+1*2+1*2*3+...+1*2*3*...n .
 *
 * @return int
 */
int S1MultiToN(int n) {
  int sum = 0, multi = 1, i, j;
  for (i = 1; i <= n; i++) {
    multi = 1;
    for (j = 1; j <= i; j++) {
      multi *= j;
    }
    sum += multi;
  }
  return sum;
}

/**
 * @brief Bài 26:   Tính S(n)=x+x^2+x^3+...+x^n .
 *
 * @return double
 */
double SXPowN(double x, int n) {
  int i;
  double sum = 0, multi;

  for (int i = 1; i <= n; i++) {
    multi = TXPowN(x, i);
    sum += multi;
  }
  return sum;
}

/**
 * @brief Bài 27:   Tính S(n)=x^2+x^4+...+x^2n .
 *
 * @return double
 */
double SXPow2N(double x, int n) {
  double multi, i, j;

  for (i = 1; i <= n; i++) {
    multi = TXPowN(x, 2 * i);
  }
  return multi;
}

/**
 * @brief Bài 28: Tính S(n)=x+x^3+x^5+...+x^(2n+1) .
 *
 * @return double
 */
double SXPow2NAdd1(double x, int n) {
  double i, multi, sum = 0;
  for (i = 1; i <= 2 * n + 1; i += 2) {
    multi = TXPowN(x, i);
    sum += multi;
  }
  return sum;
}

/**
 * @brief Bài 29: Tính S(n)=1+1/(1+2)+1/(1+2+3)+...+1/(1+2+3+...+n)
 *
 * @return double
 */
double SNDivide1AddToN(int n) {
  double sum = 0, sumTemp = 0, i, j;
  for (i = 1; i <= n; i++) {
    sumTemp = 0;
    for (j = 1; j <= i; j++) {
      sumTemp += j;
    }
    sum += (double)1 / sumTemp;
  }
  return sum;
}

/**
 * @brief Bài 30: Tính S(n)=x+x^2/(1+2)+x^3/(1+2+3)+...+x^n/(1+2+3+...+n)
 *
 * @return double
 */
double SXPowNDivide1AddToN(double x, int n) {
  double multi, sumTemp, i, j, sum = 0;
  for (i = 1; i <= n; i++) {
    multi = TXPowN(x, i);
    sumTemp = 0;
    for (j = 1; j <= i; j++) {
      sumTemp += j;
    }
    sum += multi / sumTemp;
  }
  return sum;
}

/**
 * @brief Bài 31: Tính S(n)=x+x^2/2!+x^3/3!+...+x^n/n! .
 *
 * @return double
 */
double SXPowNDivideFactorialN(double x, int n) {
  double multi, sumTemp, i, factorial, sum = 0;

  for (i = 1; i <= n; i++) {
    multi = TXPowN(x, i);
    factorial = Factorial(i);
    sum += multi / factorial;
  }
  return sum;
}

/**
 * @brief Bài 32: Tính S(n)=1+x^2/2!+x^4/4!+...+(x^(2n))/(2n)! .
 *
 * @return double
 */
double SXPowNDivideFactorial2N(double x, int n) {
  double multi, factorial, i, sum = 1;
  for (i = 1; i <= n; i++) {
    multi = TXPowN(x, 2 * i);
    factorial = Factorial(2 * i);
    sum += multi / factorial;
  }
  return sum;
}

/**
 * @brief Bài 33: Tính S(n)=x+x^3/3!+x^5/5!+...+x^(2n+1)/(2n+1)! .
 *
 * @return double
 */
double SXPow2NAdd1DivideFactorial2NAdd1(double x, int n) {
  double multi, factorial, i, sum = 0;
  for (i = 1; i <= 2 * n + 1; i += 2) {
    multi = TXPowN(x, i);
    factorial = Factorial(i);
    sum += multi / factorial;
  }
  return sum;
}

/**
 * @brief Bài 34: Tính S(x,n)=x-x^2+x^3+...+((-1)^(n+1))*(x^n) .
 *
 * @return double
 */
double SNegative1PowNAdd1MultiXPowN(double x, int n) {
  double multi, i, sum = 0;
  for (i = 1; i <= n; i++) {
    multi = TXPowN(-1, i + 1) * TXPowN(x, i);
    sum += multi;
  }
  return sum;
}

/**
 * @brief Bài 35: Tính S(x,n)=-x^2+x^4+...+(-1^n)*(x^2n) .
 *
 * @return double
 */
double SNegative1PowNMultiXPow2N(double x, int n) {
  double multi, sum = 0, i;
  for (i = 1; i <= n; i++) {
    multi = TXPowN(-1, i) * TXPowN(x, 2 * i);
    sum += multi;
  }
  return sum;
}

/**
 * @brief Bài 36: Tính S(x,n)=x-x^3+x^5+...+(-1^n)*(x^(2n+1)) .
 *
 * @return double
 */
double SNegative1PowNMultiXPow2NAdd1(double x, int n) {
  double multi, sum = 0, i;

  for (i = 0; i <= n; i++) {
    multi = TXPowN(-1, i) * TXPowN(x, 2 * i + 1);
    sum += multi;
  }
  return sum;
}

/**
 * @brief Bài 37: Tính S(n)=1-1/(1+2)+1/(1+2+3)+...+(-1^(n+1))*(1/(1+2+3+...+n))
 * .
 *
 * @return double
 */
double SNegative1PowNAdd1DivideAdd1ToN(int n) {
  double multi, sum = 0, i, sumTemp = 0;

  for (i = 1; i <= n; i++) {
    sumTemp = 0;
    multi = TXPowN(-1, i + 1);
    sumTemp += i;
    sum += multi / sumTemp;
  }
  return sum;
}

/**
 * @brief Bài 38: Tính
 * S(x,n)=-x+(x^2)/(1+2)-(x^3)/(1+2+3)+...+(-1^n)*((x^n)/(1+2+3+...+n)) .
 *
 * @return double
 */
double SNegative1PowNMultiXPowNAdd1DivideAdd1ToN(double x, int n) {
  double sum = 0, sumTemp = 0, i, j, multi;

  for (i = 1; i <= n; i++) {
    sumTemp = 0;
    multi = TXPowN(-1, i) * TXPowN(x, i);
    for (j = 1; j <= i; j++) {
      sumTemp += j;
    }
    sum += multi / sumTemp;
  }
  return sum;
}

/**
 * @brief Bài 39: Tính S(x,n)=-x+(x^2)/(2!)-(x^3)/(3!)+...+(-1^n)*((x^n)/(n!)) .
 *
 * @return double
 */
double SNegative1PowNMultiXPowNDivideFactorialN(double x, int n) {
  double sum = 0, factorial, i, j, multi;

  for (i = 1; i <= n; i++) {
    multi = TXPowN(-1, i) * TXPowN(x, i);
    factorial = Factorial(i);
    sum += multi / factorial;
  }
  return sum;
}

/**
 * @brief Bài 40: Tính
 * S(x,n)=-1+(x^2)/(2!)-(x^4)/(4!)+...+(-1^(n+1))*((x^2n)/(2n!)) .
 *
 * @return double
 */
double SNegative1Pow2NAdd1MultiXPow2NDivideFactorial2N(double x, int n) {
  double sum = -1, factorial, i, j, multi;

  for (i = 1; i <= n; i++) {
    multi = TXPowN(-1, i + 1) * TXPowN(x, 2 * i);
    factorial = Factorial(2 * i);
    sum += multi / factorial;
  }
  return sum;
}

/**
 * @brief Bài 41: Tính
 * S(x,n)=-x+(x^3)/(3!)-(x^5)/(5!)+...+(-1^(n+1))*((x^(2n+1))/((2n+1)!)) .
 *
 * @return double
 */
double SNegative1PowNAdd1MultiXPow2NAdd1DivideFactorial2N(double x, int n) {
  double sum = 0, factorial, i, j, multi;
  for (i = 0; i <= n; i++) {
    multi = TXPowN(-1, i + 1) * TXPowN(x, 2 * i + 1);
    factorial = Factorial(2 * i + 1);
    sum += multi / factorial;
  }
  return sum;
}

/**
 * @brief Bài 42: Cho n là số nguyên dương.Hãy tìm giá trị nguyên dương k lớn
 * nhất sao cho S(k)<n. Trong đó chuỗi S(k) được định nghĩa như sau:
 * S(k)=1+2+3+...+k .
 *
 * @return int
 */
int FindkLowerThanN(int n) {
  int i, sum = 0;
  for (i = 1; i <= n; i++) {
    sum += i;
    if ((sum + i + 1) >= n) {
      return i;
    }
  }
  return 0;
}

int main() {
  int n;
  double x;
  std::cout << "Input n: " << std::endl;
  InputNumber(n);

  std::cout << std::endl << "Input x: " << std::endl;
  InputNumber(x);
  std::cout << "" << std::endl;

  std::cout << "==================================================="
            << std::endl;

  std::cout << "19 S1Divide2N: " << S1Divide2N(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "20 S1Divide2NAdd1: " << S1Divide2NAdd1(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "21 S1DivideNMultiNAdd1: " << S1DivideNMultiNAdd1(n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "22 SNDivideNAdd1: " << SNDivideNAdd1(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "23 S2NAdd1Divide2MultiNAdd1: " << S2NAdd1Divide2MultiNAdd1(n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "24 TXPowN: " << std::endl;
  std::cout << "24 TXPowN: " << TXPowN(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "25 S1MultiToN: " << S1MultiToN(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "26 SXPowN: " << SXPowN(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "==================================================="
            << std::endl;

  std::cout << "27 SXPow2N: " << SXPow2N(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "28 SXPow2NAdd1: " << SXPow2NAdd1(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "29 SNDivide1AddToN: " << SNDivide1AddToN(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "30 SXPowNDivide1AddToN: " << SXPowNDivide1AddToN(x, n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "31 SXPowNDivideFactorialN: " << SXPowNDivideFactorialN(x, n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "32 SXPowNDivideFactorial2N: " << SXPowNDivideFactorial2N(x, n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "33 SXPow2NAdd1DivideFactorial2NAdd1: "
            << SXPow2NAdd1DivideFactorial2NAdd1(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "34 SNegative1PowNAdd1MultiXPowN: "
            << SNegative1PowNAdd1MultiXPowN(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "==================================================="
            << std::endl;

  std::cout << "35 SNegative1PowNMultiXPow2N: "
            << SNegative1PowNMultiXPow2N(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "36 SNegative1PowNMultiXPow2NAdd1: "
            << SNegative1PowNMultiXPow2NAdd1(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "37 SNegative1PowNAdd1DivideAdd1ToN: "
            << SNegative1PowNAdd1DivideAdd1ToN(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "38 SNegative1PowNMultiXPowNAdd1DivideAdd1ToN: "
            << SNegative1PowNMultiXPowNAdd1DivideAdd1ToN(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "39 SNegative1PowNMultiXPowNDivideFactorialN: "
            << SNegative1PowNMultiXPowNDivideFactorialN(x, n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "40 SNegative1Pow2NAdd1MultiXPow2NDivideFactorial2N: "
            << SNegative1Pow2NAdd1MultiXPow2NDivideFactorial2N(x, n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "41 SNegative1PowNAdd1MultiXPow2NAdd1DivideFactorial2N: "
            << SNegative1PowNAdd1MultiXPow2NAdd1DivideFactorial2N(x, n)
            << std::endl;
  std::cout << "" << std::endl;

  std::cout << "42 FindkLowerThanN: " << FindkLowerThanN(n) << std::endl;
  std::cout << "" << std::endl;

  return 0;
}
