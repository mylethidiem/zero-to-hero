#include "stdio.h"
#include <functional>
#include <iostream>

using namespace std;

bool Ascending(int left, int right) { return left > right; }
int main() {
  float refVariable;
  float valVariable;

  refVariable = 10.f;
  valVariable = 20.f;

  cout << "refVariable: " << refVariable << ", valVariable: " << valVariable
       << endl;

  auto F1Lamda = [&, valVariable](float a, float b) mutable noexcept -> float {
    // capture clause
    /*
    [&refVariable, valVariable]
    [valVariable, &refVariable]
    [=,&refVariable]
    [&,valVariable]
    */

    valVariable++;
    refVariable++;

    float result;
    result = a + b - (refVariable + valVariable);
    cout << "I'm in lamda expression:" << valVariable << endl;
    if (result == 25.f) {
      throw 25.f;
    }

    return result;
  };

  cout << "result: " << F1Lamda(20.f, 30.f) << endl;

  int a = 10, b = 5;
  [a, &b]() mutable {
    a = 1;
    b = 1;
    cout << "Increase " << ++ ++ ++a << endl;
  }();
  cout << "Out of lamda expression " << a << endl;

  auto var = []() -> int * { return nullptr; }; // return a pointer

  int arr[] = {1, 4, 2, 3, 6, 5, 8, 9, 7};
  int length = sizeof(arr) / sizeof(int);

  auto selectionSort = [](int *arr,
                          int lenght /*, bool(*comparisonFunc)(int, int)*/) {
    auto func = [=](int left, int right) noexcept -> bool {
      return left > right;
    };

    for (int i = 0; i < lenght - 1; i++) {
      int min = i;
      for (int i_cr = i + 1; i_cr < lenght; i_cr++) {
        if (/*comparisonFunc(arr[min], arr[i_cr])*/ func(arr[min], arr[i_cr])) {
          min = i_cr;
        }
      }
      std::swap(arr[min], arr[i]);
    }
  };

  selectionSort(arr, length);

  std::function<int(unsigned int)> Factorial;

  Factorial = [&Factorial](unsigned int i) -> int {
    if (i <= 1) {
      return 1;
    }
    return i * Factorial(i - 1);
  };

  cout << "Factorial of (10) is: " << Factorial(10) << endl;

  [] {};

  int firstVal = 5, secondVal = 15;
  int *a1 = &firstVal, *b1 = &secondVal;
  auto F2 = [=, &a1]() mutable {
    int *t = a1;
    a1 = b1;
    b1 = t;
  };
  F2();
  cout << "a: " << *a1 << "b: " << *b1 << endl;
  *a1 = firstVal;
  cout << "a: " << *a1 << "b: " << *b1 << endl;

  int one = 1, two = 2;
  auto swapFunc = [&]() {
    one = one ^ two;
    two = one ^ two;
    one = one ^ two;
  };
  swapFunc();
  cout << "one = " << one << " & two = " << two << endl;

  system("PAUSE");
  return 0;
}
