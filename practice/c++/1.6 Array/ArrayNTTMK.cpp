#include <cmath>
#include <iostream>

#define MAX 50
/**
 * ALMOST 192 EXERCISES
 */
// KỸ THUẬT NHẬP XUẤT MẢNG & * KỸ THUẬT ĐẶT LÍNH CANH CÁC BÀI TẬP CƠ BẢN
void InputArray(int a[], int n) {
  do {
    std::cout << "Input the number element: ";
    std::cin >> n;
  } while (n <= 0 || n > MAX);
  int i = 0;
  for (; i < n; i++) {
    std::cout << " Input element " << i;
    std::cin >> a[i];
  }
}

void OutputArray(int a[], int n) {
  int i = 0;
  for (; i < n; i++) {
    std::cout << " " << a[i];
  }
}

// 132/57 Show even numbers in integer array
void showString(int n) { std::cout << " " << n; }

void showString(float n) { std::cout << " " << n; }

void showString(std::string str) { std::cout << " " << str; }

void ShowEvenNumber132(int a[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (a[i] % 2 == 0) {
      showString(a[i]);
    }
  }
}
// 33/57 Show position that value is negative in float array
void ShowPositionThatValueNegative133(float a[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (a[i] < 0) {
      showString(i);
    }
  }
}

// 134/58 find max value in float array
float FindMaxValue134(float a[], int n) {
  float max = a[0];
  int i = 1;
  for (; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

// 135/58 way 1: find first positive value in float array, if negative float
// return -1
float FindFirstPositive135(float a[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (a[i] > 0) {
      return a[i];
    }
  }
}
// 136/58 Find the last even number in integer array. If array has not even
// number return -1
int FindLastEvenNumber136(int a[], int n) {
  int i = 0, value = -1;
  for (; i < n; i++) {
    if (a[i] % 2 == 0) {
      value = a[i];
    }
  }
  return value;
}
// 137/58 Find position that value is min in float array
float FindPositionThatValueMin137(float a[], int n) {
  float min = a[0];
  int i = 0;
  for (; i < n; i++) {
    if (min > a[i]) {
      min = a[i];
    }
  }
  return min;
}
// 138/58 Find the first even number in integer array, if has not even number
// return -1
int FindFirstEvenNumber138() {
  int even = -1, i = 0;
  for (; i < n; i++) {
    if (a[i] % 2 == 0) {
      even = a[i];
      break;
    }
  }
  return even;
}
// 139/58 Find last perfect number in integer array. if has not return -1
bool isPerfectNumber(int n) {
  int sum = 0, multi = 1, i = 1;
  for (; i < (int)sqrt((double)n); i++) {
    if (n % i == 0) {
      sum += i;
      multi *= i;
    }
  }
  if (sum == multi) {
    return true;
  }
  return false;
}
int LastPerfectNumber139(int a[], int n) {
  int lastPerfectNumber = -1, i = 0;
  for (; i < n; i++) {
    if (isPerfectNumber(a[i]) == true) {
      lastPerfectNumber = a[i];
    }
  }
  return lastPerfectNumber;
}
// 140-141/58 Find min positive and position in float array. if not have return
// -1
float FindMinPositiveNumber140(float a[], int n,
                               int &minPositiveValuePosition) {
  int i = 0;
  float minValue = -1.0f;
  for (; i < n; i++) {
    if (a[i] > 0) {
      minValue = a[i];
      minPositiveValuePosition = i;
      break;
    }
  }
  if (minValue < 0) {
    return minValue;
  }
  i = 0;
  for (; i < n; i++) {
    if (a[i] > 0 && a[i] < minValue) {
      minValue = a[i];
      minPositiveValuePosition = i;
    }
  }
  return minValue;
}
// CÁC BÀI TẬP LUYỆN TẬP
// 142/59 Find min value in float array
float FindMinValue142(float a[], int n) {
  int i = 0;
  float min = a[0];
  for (; i < n; i++) {
    if (a[i] < min) {
      min = a[i];
    }
  }
  return min;
}

// 143/59 Find first even positive number in integer array
int FindFirstEvenPositive143(int a[], int n) {
  int i = 0, firstEvenNumber = -1;
  for (; i < n; i++) {
    if (a[i] % 2 == 0) {
      firstEvenNumber = a[i];
      break;
    }
  }
  return firstEvenNumber;
}
// 144/59 Find first prime number in integer array. if not return -1
bool isPrimeNumber(int n) {
  if (n <= 1) {
    return false;
  }
  if (n == 2 || n == 3) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }
  // n > 3
  int i = 3;
  for (; i < (int)sqrt((double)n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int FirstPrimeNumber(int a[], int n) {
  int i = 0, firstPrimeNumber = -1;
  for (; i < n; i++) {
    if (isPrimeNumber(a[i]) == true) {
      firstPrimeNumber = a[i];
    }
  }
  return firstPrimeNumber;
}
// 145/59 Find first perfect number in integer array. if not have return -1
int FirstPerfectNumber(int a[], int n) {
  int firstPerfectNumber = -1, i = 0;
  for (; i < n; i++) {
    if (isPerfectNumber(a[i]) == true) {
      firstPerfectNumber = a[i];
      break;
    }
  }
  return firstPerfectNumber;
}
// 146/59 Find first negative in float array. if not return 0
float FirstNegative(float a[], int n) {
  int i = 0, firstNegativeNumber = 0;
  for (; i < n; i++) {
    if (a[i] < 0) {
      firstNegativeNumber = a[i];
    }
  }
  return firstNegativeNumber;
}
// 147/59 Find last positive in float array. if not havee return -1
float LastPositive(float a[], int n) {
  int i = 0, lastPositiveNumber = -1;
  for (; i < n; i++) {
    if (a[i] > 0) {
      lastPositiveNumber = a[i];
    }
  }
  return lastPositiveNumber;
}
// 148/60 Find last prime number in integer array if not have return -1
int LastPrimeNumber(int a[], int n) {
  int i = 0, lastPrimeNumber = -1;
  for (; i < n; i++) {
    if (isPrimeNumber(a[i]) == true) {
      lastPrimeNumber = a[i];
    }
  }
  return lastPrimeNumber;
}
// 149/60 Find last perfect in integer. if not have return -1
int LastPerfectNumber(int a[], int n) {
  int i = 0, lastPerfectNumber = -1;
  for (; i < n; i++) {
    if (isPerfectNumber(a[i]) == true) {
      lastPerfectNumber = a[i];
    }
  }
  return lastPerfectNumber;
}
// 150/60 Find max negative in float array. if not return 0
float MaxNegativeNumber(float a[], int n) {
  float maxNegativeNumber = 0.0f;
  int i = 0;
  for (; i < n; i++) {
    if (a[i] < 0) {
      maxNegativeNumber = a[i];
    }
  }
  if (maxNegativeNumber == 0.0f) {
    return maxNegativeNumber;
  }
  i = 0;
  for (; i < n; i++) {
    if (a[i] < 0 && a[i] > maxNegativeNumber) {
      maxNegativeNumber = a[i];
    }
  }
  return maxNegativeNumber;
}
// 151/60 Find max prime in integer array. if not return 0
int MaxPrimeNumber(int a[], int n) {
  int i = 0, maxPrimeNumber = 0;
  for (; i < n; i++) {
    if (isPrimeNumber(a[i]) == true && maxPrimeNumber < a[i]) {
      maxPrimeNumber = a[i];
    }
  }
  return maxPrimeNumber;
}
// 152/60 Find min perfect in integer array. if not have return 0
int MinPerfectNumber() {
  int minPerfectNumber = 0, i = 0;
  for (; i < n; i++) {
    if (isPerfectNumber(a[i]) == true && minPerfectNumber > a[i]) {
      minPerfectNumber = a[i];
    }
  }
  return minPerfectNumber;
}
// 153/60 Find even min in integer. if not have return -1
int MinEvenNumber(int a[], int n) {
  int i = 0, minEvenNumber = -1;
  for (; i < n; i++) {
    if (a[i] % 2 == 0) {
      minEvenNumber = a[i];
    }
  }
  if (minEvenNumber == -1) {
    return minEvenNumber;
  }
  i = 0;
  for (; i < n; i++) {
    if (a[i] % 2 == 0 && minEvenNumber > a[i]) {
      minEvenNumber = a[i];
    }
  }
  return minEvenNumber;
}
// 154/60 Find max negative. if not have return 0
int MaxNegativeNumber(int a[], int n) {
  int maxNegativeNumber = 0, i = 0;
  for (; i < 0; i++) {
    if (a[i] < 0) {
      maxNegativeNumber = a[i];
    }
  }
  if (maxNegativeNumber == 0) {
    return maxNegativeNumber;
  }
  i = 0;
  for (; i < n; i++) {
    if (a[i] < 0 && maxNegativeNumber < a[i]) {
      maxNegativeNumber = a[i];
    }
  }
  return maxNegativeNumber;
}

int main() {
  int a[MAX], n;
  InputArray(a, n);
  OutputArray(a, n);

  return 0;
}
