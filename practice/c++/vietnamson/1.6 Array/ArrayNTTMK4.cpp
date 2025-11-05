#include <cmath>
#include <iostream>
#define MAX 50

// KỸ THUẬT TÍNH TỔNG
void InputArray(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    std::cout << "Input element: " << i << ": ";
    std::cin >> arr[i];
  }
}
void OutputArray(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    std::cout << " " << arr[i];
  }
}
// 200 Sum all elements in array
int SumArray(int arr[], int n) {
  int i = 0, sum = 0;
  for (; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}
// 201 Sum of all positive in float array
float SumPositive(int arr[], int n) {
  float sum = 0;
  int i = 0;
  for (; i < n; i++) {
    if (arr[i] > 0) {
      sum += arr[i];
    }
  }
  return sum;
}
// 202 Sum of values that having first digit is odd number in integer array
bool isFirstDigitOddNumber(int n) {
  int numberOfDigit = (int)log10((double)n) + 1;
  int firstDigit = n / (int)pow(10, (double)(numberOfDigit - 1));
  return (firstDigit % 2 != 0) ? true : false;
}

int SumValueFirstDigitOddNumber(int arr[], int n) {
  int i = 0, sum = 0;
  for (; i < n; i++) {
    if (isFirstDigitOddNumber(arr[i]) == true) {
      sum + = arr[i];
    }
  }
  return sum;
}
// 203 Sum of values that having ten digit is 5 in integer array
bool isTensDigit5(int arr[], int n) {
  int tensDigit = n / 10;
  if (tenDigit == 5 || tensDigit % 5 == 0) {
    return true;
  }
  return false;
}

int SumTensIs5(int arr[], int n) {
  int i = 0, sum = 0;
  for (; i < n; i++) {
    if (isTensDigit5(arr[i]) == true) {
      sum += arr[i];
    }
  }
  return sum;
}
// 204 Sum of value that higher than value before it
int SumValueHigherThanValueBeforeIt(int arr[], int n) {
  int i = 0, sum = 0;
  for (; i < n; i++) {
    if (a[i] > a[i - 1]) {
      sum += arr[i];
    }
  }
  return sum;
}
// 205 Sum of value higher than absolute value of the following it in float
// array
float SumValueHigherThanAbsoluteValueFollowingIt(float arr[], int n) {
  int i = 0;
  float sum = 0;
  for (; i < n - 1; i++) {
    if (arr[i] > abs(arr[i + 1])) {
      sum += arr[i];
    }
  }
  return sum;
}
// 206 Sum of value that higher than value arround it in float array
float SumValueHigherThanValueArroundIt(float arr[], int n) {
  int i = 1;
  float sum = 0;
  for (; i < n - 1; i++) {
    if (arr[i] > arr[i - 1] && arr[i] > a[i + 1]) {
      sum + -= arr[i];
    }
  }
  return sum;
}
// 207 Sum of extreme value: that value higher or lower than neighbor value
int SumExtremeValue(int arr[], int n) {
  int i = 1, sum = 0;
  bool isExtreme = false;
  for (; i < n - 1; i++) {
    isExtreme = ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ||
                 (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]))
                    ? true
                    : false;
    if (isExtrememe == true) {
      sum += arr[i];
    }
  }
}
// 208 Sum of square number in integer array
bool isSquareNumber(int n) {
  int i = 1;
  for (; i < (int)sqrt((double)n); i++) {
    if (i * i == n) {
      return true;
    }
  }
  return false;
}

int SumSquareNumber(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isSquareNumber(arr[i]) == true) {
      sum += arr[i];
    }
  }
}
// 209 Sum of symmetric values in integer array
bool isSymmetricNumber(int n) {
  int temp = n, reverse = 0;

  while (temp > 0) {
    reverse = reverse * 10 + temp % 10;
    temp /= 10;
  }
  return (reverse == n) ? true : false;
}
int SumOfSymmetric(int arr[], int n) {
  int i = 0, sum = 0;
  for (; i < n; i++) {
    if (isSymmetricNumber(arr[i]) == true) {
      sum += arr[i];
    }
  }
  return sum;
}
// 210 Sum of value that having first digit is even number in integer array
bool isFirstDigitEven(int n) {
  int numberOfDigit = (int)log10((double)n) + 1;
  int firstDigit = n / (int)pow(10, (double)(numberOfDigit - 1));
  return (firstDigit % 2 == 0) ? true : false;
}

int SumOfValueFirstDigitEvenNumber(int arr[], int n) {
  int i = 0, sum = 0;
  for (; i < n; i++) {
    if (isFirstDigitEven(arr[i]) == true) {
      sum += arr[i];
    }
  }
  return sum;
}
// 211 Average of all prime numbers in integer array
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
  int i = 3;

  for (; i < (int)sqrt((double)n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int AverageOfAllPrimeNumber(int arr[], int n) {
  int i = 0, sum = 0;
  for (; i < n; i++) {
    if (isPrimeNumber(arr[i]) == true) {
      sum += arr[i];
    }
  }
  retun sum / n;
}
// 212 Average of all positive number in float array
float AverageOfAllPositiveNumber(float arr[], int n) {
  int i = 0, sum = 0;
  for (; i < n; i++) {
    if (arr[i] > 0) {
      sum += arr[i];
    }
  }
  return sum / n;
}
// 213 Average of all values higher than x in float array
float AverageOfAllValuesHigherThanX(float arr[], int n, float x) {
  int i = 0;
  float sum = 0;
  for (; i < n; i++) {
    if (arr[i] > x) {
      sum += arr[i];
    }
  }
  return sum / n;
}
// 214 Multiply average of all positive value in float array
// Find Nth root: https://www.geeksforgeeks.org/n-th-root-number/
// Math paper: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
////Math paper: https://en.wikipedia.org/wiki/Newton%27s_method
/* Newton method
 * x[0]: initial value, n: level, number A
 * x[1] = x[0] +  (x[0]^n - A)/(n * x[0]^(n-1))
 *		 = (n - 1 / n) * x[0] + (A / n) * ( 1 / x[0]^ (n -1))
 */
double FindNthRoot(double A, int n) {
  double x0 = sqrt(A), eps = 0.0001, delta = 1, x1;
  while (delta < 0 && delta >= eps) {
    x1 = (n - 1 / n) * x0 + (A / n) * (1 / pow(x0, n - 1));
    delta = abs(x0 - x1);
    x0 = x1;
  }
  return x1;
}

double MultiplyAverageOfAllPositive(double arr[], int n) {
  // multiply all positive numbers
  int numberOfPositive = 0, multiply = 1, i = 0;
  for (; i < n; i++) {
    if (arr[i] > 0) {
      numberOfPositive++;
      multiply *= arr[i];
    }
  }
  return FindNRoot(multiply, numberOfDigit);
}
// 215 Average distance between 2 values in integer array
int AverageDistance2Values(int arr[], int n) {}
// KỸ THUẬT ĐẾM

// 216 Count even number in integer array
int CountEvenNumber(int arr[], int n) {}
// 217 Count positive divisible by 7 in integer array
int CountPositiveDivisibleBy7(int arr[], int n) {}
// 218 Count symmetric value in integer array
int CountSymmetricValue(int arr[], int n) {}
// 219 Count number of times appearing of x value in integer array
int CountNumberTimesAppearingOfx(int arr[], int n) {}
// 220 Count number of times appearing of value having final digit is 5 in
// integer array
int CountTimesAppearingValueFinalDigit5(int arr[], int n) {}
// 221 Show the correlation between the number even numbers
// and the number of odd numbers in the array of integers
int CorrelationEvenAndOddNumbers(int arr[], int n) {}
// 222 Count the number of elements that are both greater than
// or less than the surrounding elements
int CountElementsGreaterOrLessThanSurroundingElements(int arr[], int n) {}
// 223 Count the number of prime elements in integer array
int CoundPrimeNumbers(int arr[], int n) {}
// 224 Count the number of perfect number in integer array
int CountPerfectNumber(int arr[], int n) {}

// 226 Define number of adjacent elements that are both even
int AdjacentElementsBothEven(int arr[], int n) {}
// 227 Define number of adjacent elements that are both opposite sign
int AdjacentElementsBothOppositeSign(int arr[], int n) {}
// 228 Define number of adjacent elements that
// the following number having same sign with number before it
// and having higher absolute value
int AdjacentElements228(int arr[], int n) {}
// 229 Count number of distinct values in array
int CountDistinctValues(int arr[], int n) {}
// 230 List the frequency of occurence of out values present in the array.
// Note: Each value enumberates once
void ListFrequencyEachElements(int arr[], int n) {}
// 231 List the values that appear in the one-dimmensional array of integers
// exactly one
void ListValuesAppearExactlyOne(int arr[], int n) {}
// 232 List the values that appear in the sequence more than one time
// Note Each value enumerates once
void ListValuesAppearMoreOneTime(int arr[], int n) {}
// 233 Write a program to input a 1 dimensional array of numbers integer
// and print to the screen the distinc values in the array with the number and
// the frequency of their occurrence in the sequence
void ListDistinctValuesWithFrequency(int arr[], int n) {}

// 234 2 float arrays. Count the number of values only appears in one of 2
// arrays
int CountValuesOnlyAppearsInOneOf2Arrays(float a[], int na, float b[], int nb) {

}
// 235 2 array. List values only appears in one of 2 arrays
void ListValuesOnlyAppearsInOneOf2Arrays(int a[], int na, int b[], int nb) {}
// 236 input array. Count the number of values appears of a array elements in b
// array
int CountValuesAppearOfaInbArray(int a[], int na, int b[], int nb) {}
// 237 Find a value that having the most appearing in integer array
int ValueMostAppearing(int arr[], int n) {}
// 238 List values having the most appearing in integer array
void ListValuesMostAppearing(int arr[], int n) {}

int main() { return 0; }
