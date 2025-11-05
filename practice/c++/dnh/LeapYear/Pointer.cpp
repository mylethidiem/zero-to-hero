#include <functional>
#include <iostream>

using namespace std;

enum pointer {
  NOTHING,
  POINTER_TYPE,
  POINTER_CHAR,
  POINTER_MEMORY_ALLOCATE,
  POINTER_FUNCTION,
  POINTER_TO_POINTER,
  POINTER_TO_FUNCTION,
  POINTER_
};
bool (*comparisonFunc)(int, int);

void swapValue(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
bool acensding(int left, int right) {
  if (left > right) {
    return true;
  }
  return false;
}
bool decesnding(int left, int right) {
  if (left < right) {
    return true;
  }
  return false;
}

void selectionSort(int *arr, int length, bool (*comparisonFunc)(int, int)) {
  // void(*swapValueFunc)(int&, int&) = swapValue;
  std::function<void(int &, int &)> swapValueFunc = swapValue;
  for (int i = 0; i < length; i++) {
    int iMark = i;
    for (int j = iMark; j < length; j++) {
      if (comparisonFunc(arr[iMark], arr[j])) {
        iMark = j;
      }
    }
    swapValueFunc(arr[iMark], arr[i]);
  }
}
void printArray(int *arr, int length) {
  for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
void setToNull(int *&ptr) { ptr = NULL; }

int main() {
  pointer test = (pointer)0;

  cout << "Choose your test: " << endl;
  cout << "===================================================================="
          "========================\n"
       << endl;
  // cin >> test;
  test = POINTER_TO_FUNCTION;

  switch (test) {
  case POINTER_TYPE: {
    cout << "\n============= POINTER_TYPE ===============" << endl;
    float *fPtr;
    float fVal = 20;
    fPtr = &fVal;
    cout << "type of &fVal: " << typeid(&fVal).name() << endl;
    break;
  }
  case POINTER_CHAR: {
    cout << "\n============= POINTER_CHAR ===============" << endl;
    char str[] = "Hello!";
    char *p_str = str;
    char c = 'a';

    cout << "&c: " << &c << endl;
    cout << "str: " << str << endl;
    cout << "type of str: " << typeid(str).name() << endl;
    cout << "p_str: " << p_str << endl;
    cout << "type of p_str: " << typeid(p_str).name() << endl;
    cout << "&str: " << &str << endl;
    cout << "type of &str: " << typeid(&str).name() << endl;
    cout << "&p_str: " << &p_str << endl;
    cout << "type of &p_str: " << typeid(&p_str).name() << endl;
    break;
  }
  case POINTER_MEMORY_ALLOCATE: {
    cout << "\n============= POINTER_MEMORY_ALLOCATE ===============" << endl;
    const int *ptr = NULL;

    int value1 = 5;
    ptr = &value1;

    int value2 = 10;
    ptr = &value2;

    int value3 = 5;
    int *const ptr2 = &value3;
    int value4 = 3;
    // ptr2 = &value4; //error

    int value5;
    const int *const ptr3 = &value5;
    int value6;

    break;
  }
  case POINTER_FUNCTION: {
    cout << "\n============= POINTER_FUNCTION ===============" << endl;
    int value = 5;
    int *pValue = &value;

    cout << "pValue point to " << pValue << endl;
    setToNull(pValue);
    if (pValue == NULL)
      cout << "pValue point to NULL" << endl;
    else
      cout << "pValue point to " << pValue << endl;
    break;
  }
  case POINTER_TO_POINTER: {
    cout << "\n============= POINTER_TO_POINTER ===============" << endl;
    int value = 100;
    int *ptr = &value;
    int **p_to_p = &ptr;

    cout << p_to_p << endl;   // print address of ptr
    cout << *p_to_p << endl;  // print address which hold by ptr
    cout << **p_to_p << endl; // print value at address which hold by ptr
    break;
  }
  case POINTER_TO_FUNCTION: {
    cout << "\n============= POINTER_TO_FUNCTION ===============" << endl;
    int arr[10] = {0, 2, 4, 5, 7, 9, 1, 3, 6, 8};
    int length = sizeof(arr) / sizeof(int);
    // acesnding
    selectionSort(arr, length, acensding);
    printArray(arr, length);
    // descending
    selectionSort(arr, length, decesnding);
    printArray(arr, length);
    break;
  }
  case POINTER_: {
    cout << "\n============= POINTER_ ===============" << endl;

    break;
  }
  default:
    break;
  }

  system("pause");
  return 0;
}
