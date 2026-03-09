#include <cmath>
#include <iostream>

void InputNumber(int &n) {
  do {
    std::cout << "Input number n: ";
    std::cin >> n;
  } while (n <= 0);
}

/**
 * @brief Bài 43: Kiểm tra số nguyên 4 byte có dạng 2^k hay không ?
 * Biết k sẽ là 1 số bất kỳ nào đó bắt đầu từ 0 -->
 * vd1: Nhập số 4 => 4 thỏa có dạng là 2^2.
 * vd2: Nhập số 5 => 5 không thỏa.
 *
 * @return int
 */
int TwoPowK(int n) {
  int i;
  double powResult = 1;
  for (i = 1; i <= n; i++) {
    powResult = pow(2, (double)i);
    if (powResult == n) {
      return i;
    }
  }
  return -1;
}
/**
 * @brief Bài 44: Kiểm tra số nguyên 4 byte có dạng a^k hay không ?
 * với a là số nhập vào từ bàn phím (2 <= a <= 9).
 * Biết k sẽ là 1 số bất kỳ nào đó bắt đầu từ 0 -->
 * vd1: Nhập số 4 và a = 3 => không thỏa
 * vd2: Nhập số 4 và a = 2 => thỏa
 *
 * @return int
 */
int AnyPowK(int n) {
  int i, j;
  double powResult = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      powResult = pow((double)i, (double)j);
      if (powResult == n) {
        std::cout << i << "^" << j << std::endl;
        return j;
      }
    }
  }
  return -1;
}
/**
 * @brief Bài 45: Tìm ra số nguyên dương n nhỏ nhất sao cho 1+2+3+...+n >10 000
 * .
 *
 * @return int
 */
int FindN() {
  int i, sum = 0;
  for (i = 1; i <= 10000; i++) {
    sum += i;
    if (sum > 10000) {
      std::cout << "sum = " << sum << std::endl;
      return i;
    }
  }
  return i;
}

/**
 * @brief Bài 46: Hãy viết chương trình liệt kê tất cả các số Amstrong nằm trong
 * đoạn [1,1 000 000] . Định nghĩa:Số Amstrong là số mà từng chữ số của nó mũ
 * theo số lượng các chữ số rồi cộng lại = chính số ban đầu =? số Amstrong.
 * vd:số 153 có 3 chữ số và 153=1^3+5^3+3^3 => 153 là số Amstrong .
 *
 * @return void
 */
bool isAmstrongNumber(int n) {
  int numberOfDigits, i, powResult, unit, sum = 0, temp;

  numberOfDigits = log10((double)n) + 1;
  temp = n;
  for (i = 1; i <= numberOfDigits; i++) {
    unit = n % 10;
    powResult = pow((double)unit, numberOfDigits);
    sum += powResult;
    n = n / 10;
  }

  if (sum == temp) {
    return true;
  }
  return false;
}

void AmstrongNumberLowerThan1Milion() {
  int i;
  for (i = 1; i <= 1000000; i++) {
    if (isAmstrongNumber(i)) {
      std::cout << " " << i << std::endl;
    }
  }
}

/**
 * @brief Bài 47: Nhập vào 1 chữ số nguyên dương n,hãy tính:
 * a/ Đếm số lượng chữ số của nó.
 * b/ Liệt kê tất cả các chữ số của nó.
 * c/ Tính tổng tất cả các chữ số của nó.
 * d/ Tính tích tất cả các chữ số của nó.
 * e/ Liệt kê và đếm số lượng các chữ số lẻ của nó.
 * f/ Liệt kê và đếm số lượng các chữ số chẵn của nó.
 * @return int
 */
int NumberOfDigits(int n) { return (int)log10((double)n) + 1; }

int SumOfAllDigits(int n) {
  int sum = 0, unit;
  while (n > 0) {
    unit = n % 10;
    sum += unit;
    n = n / 10;
  }
  return sum;
}

int MultiOfAllDigits(int n) {
  int multi = 1, unit;
  while (n > 0) {
    unit = n % 10;
    multi *= unit;
    n /= 10;
  }
  return multi;
}

int OddNumberOfAllDigits(int n) {
  int countOddNumber = 0;
  while (n > 0) {
    if ((n % 10) % 2 != 0) {
      countOddNumber++;
    }
    n /= 10;
  }
  return countOddNumber;
}

int EvenNumberOfAllDigits(int n) {
  int countEvenNumber = 0;
  while (n > 0) {
    if ((n % 10) % 2 == 0) {
      countEvenNumber++;
    }
    n /= 10;
  }
  return countEvenNumber;
}

int main() {
  int n;
  std::cout << "Input n: " << std::endl;
  InputNumber(n);

  std::cout << "==================================================="
            << std::endl;

  std::cout << "TwoPowK: " << TwoPowK(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "AnyPowK: " << AnyPowK(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "FindN: " << FindN() << std::endl;
  std::cout << "" << std::endl;

  std::cout << "AmstrongNumberLowerThan1Milion: " << std::endl;
  AmstrongNumberLowerThan1Milion();
  std::cout << "" << std::endl;

  std::cout << "NumberOfDigits: " << NumberOfDigits(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "SumOfAllDigits: " << SumOfAllDigits(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "MultiOfAllDigits: " << MultiOfAllDigits(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "OddNumberOfAllDigits: " << OddNumberOfAllDigits(n) << std::endl;
  std::cout << "" << std::endl;

  std::cout << "EvenNumberOfAllDigits: " << EvenNumberOfAllDigits(n)
            << std::endl;
  std::cout << "" << std::endl;

  return 0;
}
