#include <iostream>
// CÁC BÀI TẬP TÌM KIẾM VÀ LIỆT KÊ
void InputArray(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    std::cout << "\n Input numer: ";
    std::cin >> a[i];
  }
}

void OutputArray(float arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    std::cout << " " << a[i];
  }
}

void InputArray(float arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    std::cout << "\n Input numer: ";
    std::cin >> a[i];
  }
}

void OutputArray(float arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    std::cout << " " << a[i];
  }
}

// extra
// ex.1 Sort the positive numbers in the array of float number ascending
void Swap(float &a, float &b) {
  a = a - b;
  b = a + b a = b - a;
}
void SortPositiveNumbersAscending(float arr[], int n) {
  int i = 0, j = 0;
  for (; i < n - 1; i++) {
    if (a[i] <= 0) {
      continue;
    }
    for (j = i + 1; i < n; j++) {
      if (a[j] <= 0) {
        continue;
      }
      if (a[i] > a[j]) {
        Swap(a[i], a[j]);
      }
    }
  }
}
// ex.2 Sort the positive numbers ascending, the negative numbers descending in
// float array
void SortNegativeNumbersDescending(float arr[], int n) {
  int i = 0, j = 0;
  for (; i < n - 1; i++) {
    if (a[i] >= 0) {
      continue;
    }
    for (j = i + 1; j < n; j++) {
      if (a[j] >= 0) {
        continue;
      }
      if (a[i] < a[j]) {
        Swap(a[i], a[j]);
      }
    }
  }
}

void SortSignNumbersEx2(float arr[], int n) {
  SortPositiveNumbersAscending(arr, n);
  SortNegativeNumbersDescending(arr, n);
}

// ex.3 Sort the even, odd numbers ascending in integer array
void Swap(int &a, int &b) {
  a = a - b;
  b = a + b;
  a = b - a;
}
void SortEvenNumbersAscending(int arr[], int n) {
  int i = 0, j = 0;
  for (; i < n - 1; i++) {
    if (a[i] % 2 != 0) {
      continue;
    }
    for (j = i + 1; j < n; j++) {
      if (a[j] % 2 != 0) {
        continue;
      }
      if (a[i] > a[j]) {
        Swap(a, b);
      }
    }
  }
}

void SortOddNumbersAscending(int arr[], int n) {
  int i = 0, j = 0;
  for (; i < n; i++) {
    if (a[i] % 2 == 0) {
      continue;
    }
    for (j = i + 1; j < n; j++) {
      if (a[j] % 2 == 0) {
        continue;
      }
      if (a[i] > a[j]) {
        Swap(a, b);
      }
    }
  }
}

void SordEvenOddNumbersEx3(int arr[], int n) {
  SortEvenNumbersAscending(arr, n);
  SortOddNumbersAscending(arr, n);
}

// 176 List all negative in float array
void ListNegativeNumbers(float arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
                if (a]i] < 0)
		{
                  std::cout << " " << a[i];
                }
  }
}

// 177 List values in float array [x,y]
void ValueXY(float arr[], int n, float x, float y) {
  int i = 0;
  if (x < y || x >= n || y >= n) {
    std::cout << "Invalid value x, y, n" << std::endl;
    return;
  }

  for (i = x; i <= y; i++) {
    std::cout << " " << a[i];
  }
}

// 178 List even values in [x,y] integer
void ListEvenValuesXY(int arr[], int n, int x, int y) {
  int i = 0;
  if (x < y || x >= n || y >= n) {
    std::cout << "Invalid value x, y, n" << std::endl;
    return;
  }
  for (i = x; i <= y; i++) {
    if (a[i] % 2 == 0) {
      std::cout << " " << a[i];
    }
  }
}

// 179 List value satify condition: greater than the absolute value of
// the value immediately following it
void ListValue179(int arr[], int n) {
  int i = 0;
  for (; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      std::cout << " " << a[i];
    }
  }
}

// 180 List value satify condition: lower than the absolute value of
// the  value immediately following it and greater than value immediately
// preceding it
void ListValue180(int arr[], int n) {
  int i = 0;
  for (i = 1; i < n - 1; i++) {
    if (a[i] > a[i - 1] && a[i] < a[i + 1]) {
      std::cout << " " << a[i];
    }
  }
}
// 181 List even value having at least 1 value beside is even number
void ListValue181(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (i == 0) {
      if (a[1] % 2 == 0) {
        std::cout << " " << a[0];
      }
    } else if (i == n - 1) {
      if (a[n - 2] % 2 == 0) {
        std::cout << " " << a[n - 1];
      }
    } else {
      if (a[i + 1] % 2 == 0 || a[i - 1] % 2 == 0) {
        std::cout << " " << a[i];
      }
    }
  }
}
// 182 List all values in array that having at least 1 neighbor value with
// opposite sign
void ListValues182(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (i == n - 1) {
      if (a[n - 2] * a[n - 1] < 0) {
        std::cout << " " << a[n - 1];
      }
    } else if (i == 0) {
      if (a[0] * a[1] < 0) {
        std::cout << " " << a[0];
      }
    } else {
      if (a[i - 1] * a[i] < 0 || a[i] * a[i + 1]) {
        std::cout << " " << a[i];
      }
    }
  }
}
// 183 List position that value at position is max value in float array
int MaxValue(float arr[], int n) {
  int i = 0;
  float max = a[0];
  for (; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}
void ListPosition183(float arr[], int n) {
  int i = 0;
  float max;
  max = MaxValue(arr, n);
  for (; i < n; i++) {
    if (max == arr[i]) {
      std::cout << " " << i;
    }
  }
}
// 184 List position that value at position is prime number in integer array
bool isPrimeNumber(int n) {
  if (n <= 1) {
    return false;
  }
  if (n == 2 || n == 3) {
    return true;
  }
  i = 3;
  for (; i < (int)sqrt((double)n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void ListPositionPrimeNumber(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isPrimeNumber(arr[i]) == true) {
      std::cout << " " << i;
    }
  }
}

// 185 List position that value at position is square number in integer array
bool isSquareNumber(int n) {
  int squareNumber = 0;
  squareNumber = (int)pow(sqrt((double)n), 2);
  return squareNumber == n ? true : false;
}

void ListPositionSquareNumber(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isSquareNumber(arr[i]) == true) {
      std::cout << " " << i;
    }
  }
}

// 186 List position in float array that value at position equal first negative
// number
float FirstNegativeNumber(float arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (arr[i] < 0) {
      return arr[i]'
    }
  }
  return 0;
}

void ListPositionEqualFirstNegativeNumber(int arr[], int n) {
  float firstNegativeNumber = FirstNegativeNumber(arr, n);
  if (firstNegativeNumber == 0) {
    std::cout << "There are no negative Number" << std::endl;
  } else {
    int i = 0;
    for (; i < n; i++) {
      if (arr[i] == firstNegativeNumber) {
        std::cout << " " << i;
      }
    }
  }
}
// 187 List position that position at value is min positive in float array
float MinValue(float arr[], int n) {
  int i = 1;
  float min = arr[0];
  for (; i < n; i++) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return arr[i];
}

void ListPositionEqualMinValue(float arr[], int n) {
  int i = 0;
  float min = MinValue(arr, n);
  for (; i < n; i++) {
    if (arr[i] == min) {
      std::cout << " " << i;
    }
  }
}
// 188 List max even position in integer array
void ListMaxEvenPosition(int arr[], int n) {
  int i = n - 1;
  for (; i > = 0; i--) {
    if (i % 2 == 0) {
      std::cout << " " << i;
    }
  }
}
// 189 List value in integer array that value having first digit is odd number
bool isFirstDigitOddNumber(int n) {
  int numberOfDigit = (int)log10((double)n) + 1, i = 0;
  int firstDigit = n / (int)pow(10, (double)(numberOfDigit - 1));
  return (firstDigit % 2 != 0) ? true : false;
}

void ListValueFirstDigitOdd(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isFirstDigitOddNumber(arr[i]) == true) {
      std::cout << " " << arr[i];
    }
  }
}
// 190 List value in integer array that value having all digits is odd number
bool isAllDigitsOddNumber(int n) {
  while (n >= 0) {
    if ((n % 10) % 2 == 0) {
      return false;
    }
    n /= 10;
  }
  return true;
}
void ListValueAllDigitsOddNumber(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isAllDigitsOddNumber(arr[i]) == true) {
      std::cout << " " << arr[i];
    }
  }
}
// 191 List maxima value in float array: that maxima element is higher than
// neighbor value
void ListMaximaValue(float arr[], int n) {
  int i = 1;
  for (; i < n - 1; i++) {
    if (a[i] > a[i + 1] && a[i] > a[i - 1]) {
      std::cout << " " << arr[i];
    }
  }
}
// 192 List value in integer array having first digit is even
bool isFirstDigitEvenNumber(int arr[], int n) {
  int numberOfDigit = (int)log10((double)n) + 1;
  int firstDigit;
  firstDigit =
      n / (int)pow(10, (double)(numberOfDigit - 1)) return (firstDigit % 2 == 0)
          ? true
          : false;
}
void ListValueFirstDigitEven(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isFirstDigitEvenNumber(arr[i]) == true) {
      std::cout << " " << arr[i];
    }
  }
}
// 193 List value having 3^k form, if not return 0
bool is3PowkForm(int n) {
  int i = 0, form3PowkNumber = 0;
  while (form3PowkNumber < n) {
    form3PowkNumber = (int)pow(3, (double)i);
    if (form3PowkNumber == n) {
      return true;
    }
  }
  return false;
}
void ListValue3Powk(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (is3PowkFor(arr[i]) == true) {
      std::cout << " " << arr[i];
    }
  }
}
// 196 List negative in float array
void ListNegative(float arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (arr[i] < 0) {
      std::cout << " " << arr[i];
    }
  }
}
// 197 List value in integer array having first digit is odd number
void ListValueFirstDigitOdd(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isFirstDigitOddNumber(arr[i]) == true) {
      std::cout << " " << arr[i];
    }
  }
}
// 198 List position that value at position is the max value in float array
void ListPositionMax198(float arr[], int n) {
  int i = 0, maxValue;
  maxValue = MaxValue(arr, n);
  for (; i < n; i++) {
    if (arr[i] == maxValue) {
      std::cout << " " << arr[i];
    }
  }
}
// 199 List position that value at position is prime in integer array
void ListPosition(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isPrimeNumber(arr[i]) == true) {
      std::cout << " " << i;
    }
  }
}
// ex.4 input array and using algorithm find Linear Exhaustive
// find Linear Sentinel and find Binary Search
// Read more here:
// http://dulieu.tailieuhoctap.vn/books/cong-nghe-thong-tin/lap-trinh-ung-dung/file_goc_778914.pdf
// 1.1 Tìm kiếm tuần tự vét cạn Exhaustive Linear
int ExhaustiveLinear(int arr[], int n, int x) {
  int i = 0;
  for (; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}
// 1.2 Tìm kiếm tuần tự lính canh
int LinearSentinel(int arr[], int n, int x) {
  int i = 0;
  arr[n] = x;
  for (;; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
}
// 2. Tìm kiếm nhị phân với dãy A đã đc sắp xếp
int BinarySearch(int arr[], int n) {
  int l = 0, r = n - 1, m = (l + r) / 2;
  while (l <= r) {
    if (a[m] == x) {
      return m;
    } else {
      if (x < a[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
      m = (l + r) / 2;
    }
  }
  return -1;
}
// ex.5 Write a program to input an array of integers and integers k
//(1<=k<=number of distinct values in the array).
// Find the kth largest value of the array
bool isValueInArray(int arr[], int n, int x) {
  int i = 0;
  for (; i < n; i++) {
    if (arr[i] == x) {
      return true;
    }
  }
  return false;
}

int FindkThLargest(int arr[], int n, int k = 0) {
  int i = 0, DiffArr[MAX], ndiff = 0;
  for (; i < n; i++) {
    if (isValueInArray(DiffArr, ndiff, arr[i]) == true) {
      DiffArr[ndiff++] = arr[i];
    }
  }
  do {
    std::cout << "\n Input k value: ";
    std::cin >> k;
    if (k < 1 || k > ndiff) {
      std::cout << "k value must between 1 and " << ndiff << std::endl;
    }
  } while (k < 1 || k > ndiff);
  return DiffArr[ndiff--];
}
int main() { return 0; }
