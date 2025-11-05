#include <cmath>
#include <iostream>
#define MAX 50
// BÀI TẬP LUYỆN TẬP TƯ DUY
// 155/61 Find value in float that "furthest from x value"
float FurthestFromXValue155(float a[], int n, float x) {
  int i = 1;
  float substractWithX = abs(a[0] - x), furthestFromXNumber = a[0];

  for (; i < n; i++) {
    if (substractWithX < abs(a[i] - x)) {
      furthestFromNumber = a[i];
      substractWithX = abs(a[i] - x);
    }
  }
  return furthestFromXNumber;
}

// 156/61 Find a position in float array that "nearest from x value"
float NearestFromXValue156(float a[], int n, float x) {
  int i = 1;
  float substractWithX = abs(a[0] - x), nearestFromXValue = a[0];

  for (; i < n; i++) {
    if (substractWithX > abs(a[i] - x)) {
      nearestFromXValue = a[i];
      substractWithX = abs(a[i] - x);
    }
  }
  return nearestFromXValue;
}
// 157/61 Find [a,b] that contain all values in float array
//  valueDiffInArray contain different values in array having size sizeDiff
//  i from 0 to n: checking from i to i + sizeDiff, each valueDiffInArray will
//  be checked if i + sizeDiff > n, show that we don't have [a,b] => end else
//  each valueDiffInArray contain 1 time in [i,i+sizeDiff] array if not contain
//  or contain 2 times return false
int isArrayContainValue(float a[], int n, float value) {
  int i = 0, count = 0;
  for (; i < n; i++) {
    if (a[i] == value) {
      count++;
    }
  }
  return count;
}
int isArrayContainValue(float a[], int n, float value, int &position) {
  int i = 0, count = 0;
  for (; i < n; i++) {
    if (a[i] == value) {
      count++;
      position = i;
    }
  }
  return count;
}
int isArrayContainValue(float a[], int a, int b, float value) {
  int i = a, count = 0;
  for (; i < b + 1; i++) {
    if (a[i] == value) {
      count++;
    }
  }
  return count;
}

void FindSegmentabContainingAllElementsInArray(float arr[], int n) {
  int i = 1, sizeDiff = 1;
  float valueDiffInArray[MAX];
  valueDiffInArray[0] = arr[0];
  for (; i < n; i++) {
    if (isArrayContainValue(valueDiffInArray, sizeDiff, arr[i]) == 0) {
      valueDiffInArray[sizeDiff++] = arr[i];
    }
  }
  i = 0;
  int j = 0;
  float a = 0, b = 0, aResult = 0,
        bResult = n - 1; // default result is a full array
  bool isContainAllElements = false;
  b = a + sizeDiff;
  while (a + sizeDiff < n) {
    for (; j < sizeDiff, b < n;) {
      if (isArrayContainValue(arr, a, b, valueDiffInArray[j]) == 0) {
        do {
          b++;
        } while (b < n ||
                 isArrayContainValue(arr, a, b, valueDiffInArray[j]) == 0);
        if (b >= n) {
          break;
        } else {
          j++;
        }
      } else {
        j++;
      }
    }
    if (j == sizeDiff) {
      if (bResult - aResult != 0 && b - a < bResult - aResult) {
        aResult = a;
        bResult = b;
      }
      isContainAllElements = true;
    }
    a++;
    isContainAllElements = false;
    b = a + sizeDiff;
    j = 0;
  }
}

// 158/61 Find x that [-x,x] contain all elements in float array
void FindSegmentabContainingAllElementsInArray158(float arr[], int n) {
  int i = 0, sizeDiff = 1;
  bool flag = false;
  // check positive array
  for (; i < n; i++) {
    if (arr[i] > 0) {
      flag = true;
    } else {
      flag = false;
      break; // not positive array
    }
  }
  if (flag == true) {
    return;
  }
  // check negative array
  flag = false;
  i = 0;
  for (; i < n; i++) {
    if (arr[i] < 0) {
      flag = true;
    } else {
      flag = false;
      break; // not negative array
    }
  }
  if (flag == true) {
    return;
  }

  float valueDiffInArray[MAX];
  valueDiffInArray[0] = arr[0];
  i = 0;
  flag = false; // to check symmetric array
  // contain any symmetric
  float a = 0, b = 0, aResult = 0, bResult; // default result is a full array
  int position = -1;
  for (; i < n; i++) {
    if (isArrayContainValue(arr, n, -arr[i], position) > 0) {
      flag = true;
      if (i > position) {
        aResult = position;
        bResult = i;
      } else if (i < position) {
        aResult = i;
        bResult = position;
      }
      break; // having at least one symmetric number
    }
  }
  i = 1;

  for (; i < n; i++) {
    if (isArrayContainValue(valueDiffInArray, sizeDiff, arr[i]) == 0) {
      valueDiffInArray[sizeDiff++] = arr[i];
    }
  }
  i = 0;
  int j = 0;

  bool isContainAllElements = false;
  while (a + sizeDiff < n) {
    for (; j < sizeDiff, b < n;) {
      if (isArrayContainValue(arr, a, b, valueDiffInArray[j]) == 0) {
        do {
          b++;
        } while (b < n ||
                 isArrayContainValue(arr, a, b, valueDiffInArray[j]) == 0);
        if (b >= n) {
          break;
        } else {
          j++;
        }
      } else {
        j++;
      }
    }
    if (j == sizeDiff) {
      if (bResult - aResult != 0 && b - a < bResult - aResult) {
        aResult = a;
        bResult = b;
      }
      isContainAllElements = true;
    } else {
      a++;
      isContainAllElements = false;
      b = a + sizeDiff;
      j = 0;
    }
  }
}
// 159/61 Find first value > 2003 in float array, if not have return 0
float FindFirstValueHigher2003(float arr[], int n) {
  int i = 0, higher2003Number = 0;
  for (; i < n; i++) {
    if (arr[i] > 2003) {
      higher2003Number = arr[i];
      break;
    }
  }
  return higher2003Number;
}
// 160/62 Find last negative value > -1 in float array, if not return 0
float LastNegativeValueHigherNegative1(float arr[], int n) {
  int i = n - 1;
  float lastNegativeNumber = 0.0f;
  for (; i >= 0; i--) {
    if (lastNegativeNumber > -1 && lastNegativeNumber < 0) {
      lastNegativeNumber = arr[i];
    }
  }
  return lastNegativeNumber;
}
// 161 Find first value in (x,y) in integer array, if not return (?x) false
bool FindFirstValue(int arr[], int n, int value, int &position) {
  int i = 0;
  position = -1;
  for (; i < n; i++) {
    if (arr[i] == value) {
      position = i;
      return true;
    }
  }
  return false;
}
bool FirstValueXY(int arr[], int n, int x, int y, int &firstValue) {
  int i = 0, firstValue = x;
  int positionX = -1, positionY = -1;
  positionX = FindFirstVaue(int arr[], n, x, positionX);
  positionY = FindFirstVaue(int arr[], n, y, positionY);
  if (positionX == -1 || positionY == -1 || positionX > positionY) {
    return false;
  }
  firstValue = arr[postionX + 1];
  return true;
}

// 162 Find position: There 2 values beside. The value equal multi 2 values
// beside. if not have return -1
int FindPosition162(int arr[], int n) {
  int i = 1, multi = 1, positionResult = -1;
  for (; i < n - 1; i++) {
    multi = a[i - 1] * a[i + 1];
    if (a[i] == multi) {
      positionResult = i;
    }
  }
  return postitionResult;
}

// 163 Find first square number in integer array
bool isSquareNumber(int n) {
  int i = 0, powResult = 1;
  for (; i < (int)sqrt((double)n); i++) {
    powResult = (int)pow((double)i, 2);
    if (powResult == n) {
      return true;
    }
  }
  return false;
}
int FindFirstSquareNumber(int arr[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isSquareNumber(arr[i]) == true) {
      return arr[i];
    }
  }
  return -1;
}
// 164 Find first value in integer array that is "số gánh"
bool isSymmetricalNumber(int n) {
  int i = 0, reverseNumber = 0, temp = n;
  while (temp > 0) {
    reverseNumber = reverseNumber * 10 + temp % 10;
    temp /= 10;
  }
  if (reverseNumber == n) {
    return true;
  }
  return false;
}
int FirstNumberOfBurden(int arr[], int n) {
  int i = 0, burdenNumber = -1;
  for (; i < n; i++) {
    if (isSymmetricalNumber(arr[i]) == true) {
      burdenNumber = arr[i];
      break;
    }
  }
  return burdenNumber;
}
// 165 Find first value in integer array having first digit is odd number, if
// not return 0
bool isFirstDigitOddNumber(int n) { return ((n % 10) % 2 != 0) ? true : false; }
int FindFirstValue165(int arr[], int n) {
  int i = 0, result = 0;
  for (; i < n; i++) {
    if (isFirstDigitOddNumber(arr[i]) == true) {
      result = arr[i];
      break;
    }
  }
  return result;
}

// 166 Find first value 2^k, if not have return 0
bool isPow2Form(int n) {
  int i = 0, powResult;
  for (; i < (int)sqrt((double)n); i++) {
    powResult = (int)powResult(2, (double)i);
    if (powResult == n) {
      return true;
    }
  }
  return false;
}

int FirstValuePow2Form(int arr[], int n) {
  int i = 0, result = 0;
  for (; i < 0; i++) {
    if (isPow2Form(arr[i]) == true) {
      result = arr[i];
      break;
    }
  }
  return result;
}

// 167 Find value that all digits is odd number and max value and is the max
// value in integer array, if not return 0
bool isAllDigitsOddNumber(int n) {
  while (n > 0) {
    if (n % 2 == 0) {
      return true;
    }
    n /= 10;
  }
  return false;
}
int MaxValueAllDigitsOddNumber(int arr[], int n) {
  int i = 0, maxValueAllDigitsNumber = 0;
  for (; i < n; i++) {
    if (isAllDigitsOddNumber(arr[i]) == true) {
      if (maxValueAllDigitsNumber == 0 ||
          maxValueAllDigitsNumber != 0 && maxValueAllDigitsNumber < arr[i]) {
        maxValueAllDigitsNumber = arr[i];
      }
    }
  }
  return maxValueAllDigitsNumber;
}
// 168 Find max value having form 5^k in integer array if not have return 0
bool isPow5Form(int n) {
  int i = 0, powResult = 0;
  for (; i < (int)sqrt((double)n); i++) {
    powResult = (int)pow(5, (double)i);
    if (powResult == n) {
      return true;
    }
  }
  return false;
}

int FindMaxValuePow5Form(int arr[], int n) {
  int i = 0, maxValuePow5Form = 0;
  for (; i < n; i++) {
    if (isPow5Form(arr[i]) == true) {
      if (maxValuePow5Form == 0 ||
          maxValuePow5Form != 0 && maxValuePow5Form < arr[i]) {
        maxValuePow5Form = arr[i];
      }
    }
  }
  return maxValuePow5Form;
}
// 169 Find max even number lower than all odd number in integer array, if not
// return 0
bool isLowerThanAllOddNumber(int arr[], int n, int value) {
  int i = 0;
  for (; i < n; i++) {
    if (arr[i] % 2 != 0 && value > arr[i]) {
      return false;
    }
  }
  return true;
}

int FindMaxEvenNumberLowerThanAllOddNumber(int n) {
  int i = 0, maxEvenNumber = 0;
  for (; i < n; i++) {
    if (arr[i] % 2 == 0 && isLowerThanAllOddNumber(arr[i])) {
      if (maxEvenNumber == 0 || maxEvenNumber !0 && maxEvenNumber < arr[i]) {
        maxEvenNumber = arr[i];
      }
    }
  }
  return maxEvenNumber;
}

// 170 Find min prime number higher than all the last value in integer array
bool isPrimeNumber(int n) {
  if (n < 0 || n == 1) {
    return false;
  }
  if (n == 2 || n == 3) {
    return true;
  }
  // n > 3
  int i = 3;
  for (; i < (int)sqrt((double)n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return false;
}
int MaxValue(int arr[], int n) {
  int i = 0, max = arr[0];
  for (i = 1; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}
int MinPrimeNumberHigherThanOthers(int arr[], int n) {
  int maxValue, i = 0;
  maxValue = MaxValue(arr, n);

  for (i = maxValue + 1;; i++) {
    if (isPrimeNumber(i) == true && i > maxValue) {
      maxValue = i;
      break;
    }
  }
  return maxValue;
}

// 171 Find greatest common divisor of all elements in positive integer array
void FindDivisor(int arr[], int &j, int number) {
  int i = 2;
  j = 1;
  arr[0] = 1;
  for (; i <= number; i++) {
    if (number % i == 0 && isPrimeNumber(i)) {
      arr[j++] = i;
    }
  }
}

bool isValueInArray(int arr[], int n, int value) {
  int i = 0;
  for (; i < n; i++) {
    if (arr[i] == value) {
      return true;
    }
  }
  return false;
}

void CommonDivisor(int a1[], int &n1, int a2[], int &n2, int result[], int n) {
  int i = 0;
  n = 0;
  for (; i < n1; i++) {
    if (isValueInArray(a2, n2, a1[i]) == true) {
      result[n++] = a1[i];
    }
  }
}

void CopyArray(int dest[], int &ndest = 0, int src[], int nsrc = 0) {
  int i = 0;
  ndest = 0;
  for (; i < nsrc; i++) {
    dest[ndest++] = src[i];
  }
}

int FindGreatestCommonDivisor(int arr[], int n) {
  int a1[MAX], n1 = 0, a2[MAX], n2 = 0, temp[MAX], ntemp = 0, i = 2, result;
  FindDivisor(a1, n1, arr[0]);
  FindDivisor(a2, n2, arr[1]);
  for (; i < n; i++) {
    CommonDivisor(a1, n1, a2, n2, temp, ntemp); // temp
    CopyArray(a1, n1, temp, ntemp);             // a1
    (a2, n2, arr[i]);                           // a2
  }
  result = MaxValue(temp, ntemp);
  return result;
}

// 172 Find least common multiple of all elements in positive integer array
void Divisor2Arrays(int a1[], int n1, int a2[], int n2, int result[],
                    int nResult = 0) {
  int i = 0;
  for (; i < n1; i++) {
    if (isValueInArray(result, nResult, a1[i]) == false) {
      result[nResult++] = a1[i];
    }
  }
  i = 0;
  for (; i < n2; i++) {
    if (isValueInArray(result, nResult, a2[i]) == false) {
      result[nResult++] = a2[i];
    }
  }
}

int FindLeastCommonMultiple(int arr[], int n) {
  int a1[MAX], a2[MAX], temp[MAX], ntemp = 0, n1 = 0, n2 = 0, multiple = 1,
                                   i = 2;
  FindDivisor(a1, n1, arr[0]);
  FindDivisor(a2, n2, arr[1]);
  for (; i < n; i++) {
    Divisor2Arrays(a1, n1, a2, n2, temp, ntemp); // temp
    CopyArray(a1, n1, temp, ntemp);              // a1
    FindDivisor(a2, n2, arr[1]);                 // a2
  }
  i = 0;
  // temp is result
  for (; i < ntemp; i++) {
    multiple *= temp[i];
  }
  return multiple;
}
// 173 Find least number appearing in integer array
int NumberAppearing(int arr[], int n, int value) {
  int i = 0, count = 0;
  for (; i < n; i++) {
    if (arr[i] == value) {
      count++;
    }
  }
  return count;
}
int FindLeastNumberAppearing(int arr[], int n) {
  int i = 0, maxAppearing = 0, result = 0;
  for (; i < n; i++) {
    if (NumberAppearing(arr[i]) > maxAppearing) {
      result = arr[i];
      maxAppearing = NumberAppearing(arr[i]);
    }
  }
  return resultr;
}

int main() { return 0; }
