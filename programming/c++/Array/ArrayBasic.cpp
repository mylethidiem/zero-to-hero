#include <cmath>
#include <iostream>
#define MAX 50
void InputArray(int a[], int n) {
  do {
    std::cout << "\n Input number element of array: ";
    std::cin >> n;
  } while (n < 0 || n > MAX);
  int i = 0;
  for (; i < n; i++) {
    std::cout << "\n The element " << i << ": ";
    std::cin >> a[i];
  }
}

void OutputArray(int a[], int n) {
  int i = 0;
  std::cout << std::endl;
  for (; i < n; i++) {
    std::cout << a[i] << " ";
  }
}

// Even array
bool isEvenArray(int a[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if ((a[i] % 2) != 0) {
      return false;
    }
  }
  return true;
}

// Prime array
bool isPrimeNumber(int n) {
  if (n <= 0 || n == 1) {
    return false;
  }

  if (n == 2 || n == 3) {
    return true;
  }

  if (n % 2 == 0) {
    return false;
  }
  // n > 3, check from i = 3 to sqrt(n)
  int i = 3;
  for (; i < (int)sqrt((double)n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool PrimeArray(int a[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isPrimeNumber(a[i]) == false) {
      return false;
    }
  }
  return true;
}
// Inscrease array: 1, 2, 3...
bool InscreaseArray(int a[], int n) {
  int i = 0;
  for (; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}
// How many number divisible by 4 but not divisible by 5
int CountNumberDivisible4Not5(int a[], int n) {
  int i = 0, count = 0;
  for (; i < n; i++) {
    if ((a[i] % 4 == 0) && (a[i] % 5 != 0)) {
      count++;
    }
  }
  return count;
}

// Sum of prime number
int SumOfPrimeNumber(int a[], int n) {
  int sum = 0, i = 0;
  for (; i < n; i++) {
    if (isPrimeNumber(a[i])) {
      sum += a[i];
    }
  }
  return sum;
}
// Last position of x element
int LastPositionOfElement(int a[], int n, int x) {
  int i = 0, position = -1;

  for (; i < n; i++) {
    if (a[i] == x) {
      position = i;
    }
  }
  return position;
}
// First position prime number
int FirstPositionPrimeNumber(int a[], int n) {
  int i = 0, position = -1;
  for (; i < n; i++) {
    if (isPrimeNumber(a[i]) == true) {
      position = i;
    }
  }
  return i;
}

// Min number
int MinNumber(int a[], int n) {
  int min = a[0], i = 0;
  for (; i < n; i++) {
    if (a[i] < min) {
      min = a[i];
    }
  }
  return min;
}

// Positive min number: -1 if negative array
int MinPositiveNumber(int a[], int n) {
  int min = -1, i = 0, j = 0;
  for (; j < n; j++) {
    if (a[j] > 0) {
      min = a[j];
      break;
    }
  }
  if (min == -1) {
    return -1;
  }
  for (; i < n; i++) {
    if (a[i] > 0 && a[i] < min) {
      min = a[i];
    }
  }
  return min;
}

// Get the prime number in array a into array b
void SeperatePrimeNumber(int a[], int na, int b[], int &nb = 0) {
  int i = 0;
  for (; i < na; i++) {
    if (isPrimeNumber(a[i]) == true) {
      b[nb] = a[i];
      nb++;
    }
  }
}
// Seperate array a into b(positive number), c(the last)
void SeperatePositivePrimeNumber(int a[], int na, int b[], int &nb = 0, int c[],
                                 int &nc = 0) {
  int i = 0;
  for (; i < na; i++) {
    if (a[i] > 0) {
      b[nb] = a[i];
      nb++;
    } else {
      c[nc++] = a[i];
    }
  }
}
// Arrange array descrease
void Swap(int &a, int &b) {
  a = a - b;
  b = a + b;
  a = b - a;
}

void ArrangeArrayDescrease(int a[], int n) {
  int i = 0, j = 0;
  for (; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        Swap(a[i], a[j]);
      }
    }
  }
}

// Arrange array positive element in the first descrease,
//  next is negative inscrease, last is 0 numbers
void ArrangeArrayInscrease(int a[], int n) {
  int i = 0, j = 0;
  for (; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        Swap(a[i], a[j]);
      }
    }
  }
}

void ArraySpecial(int a[], int n) {
  int positive[MAX], negative[MAX], zero[MAX];
  int n_positive = 0, n_negative = 0, n_zero = 0, i = 0;
  for (; i < n; i++) {
    if (a[i] > 0) {
      positive[n_positive++] = a[i];
    } else if (a[i] < 0) {
      negative[n_negative++] = a[i];
    } else {
      zero[n_zero++] = a[i];
    }
  }
  ArrangeArrayDescrease(positive, n_positive);
  ArrangeArrayInscrease(negative, n_negative);
  // re-union
  for (i = 0; i < n; i++) {
    if (i < n_positive - 1) {
      a[i] = positive[i];
    } else if (i < n_positive + n_negative - 1) {
      int j = 0;
      for (; j < n_negative; j++) {
        a[i] = negative[j]
      }
    } else {
      int j = 0;
      for (; j < n_zero; j++) {
        a[i] = zero[j]
      }
    }
  }
}
// Change prime number in array into 0
void PrimeNumberIntoZero(int a[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isPrimeNumber(a[i]) == true) {
      a[i] = 0;
    }
  }
}
// Insert 0 after prime number
void InsertIntoArray(int a[], int &n, int position, int value) {
  int i = n - 1;
  for (; i > 0; i--) {
    a[i + 1] = a[i];
    if (i == position) {
      a[i] = value;
      n++;
    }
  }
}
void InsertZeroAfterPrimeNumber(int a[], int n) {
  int i = 0;
  for (; i < n; i++) {
    if (isPrimeNumber(a[i]) == true) {
      InsertIntoArray(a, n, i + 1, 0);
      break;
    }
  }
}
// Clear all prime number in array
void DeleteElementInArray(int a[], int &n, int position) {
  int i = position;
  for (; i < n - 1; i++) {
    a[i] = a[i + 1];
    n--;
  }
}
void DeletePrimeNumber(int a[], int n) {
  int i = 0;
  for (; i < n; ++) {
    if (isPrimeNumber(a[i]) == true) {
      DeleteElementInArray(a, n, i);
    }
  }
}

int main() {
  int a[MAX], n;
  InputArray(a, n);
  OutputArray(a, n);

  // ACTIVITY

  return 0;
}
