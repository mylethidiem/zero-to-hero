#include <cmath>
#include <iostream>
#define MAX 50
int compare2Array(int a[], int b[], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      return 1; // array a is greater than array b
    }
    if (a[i] > b[i]) {
      return 2; // array b is greater than array a
    }
    continue;
  }
  return 0;
}
void copy(int a[], int b[], int n) {
  for (int i = 0; i < n; i++) {
    a[i] = b[i];
  }
}
void Swap2Array(int a[], int b[], int n) {
  int Temp[MAX];
  // swap temp and a: Temp = a
  copy(Temp, a, n);
  // swap a and b: a = b
  copy(a, b, n);
  // swap a and b: b = Temp
  copy(b, Temp, n);
}

void compare(int *bigArray[], int numberOfArray, int n) {
  for (int i = 1; i <= numberOfArray; i++) {
    for (int j = i + 1; j < numberOfArray; j++) {
      int result = compare2Array(bigArray[i], bigArray[j], n);
      if (result = 1) {
        Swap2Array(bigArray[i], bigArray[j], n);
      }
    }
  }
}
int main() { return 0; }
