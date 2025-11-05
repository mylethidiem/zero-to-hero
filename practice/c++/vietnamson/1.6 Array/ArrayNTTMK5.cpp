#include <cmath>
#include <iostream>
#define MAX 50

// KỸ THUẬT ĐẶT CỜ HIỆU
void InputArray(int a[], int n) {}
void OutputArray(int a[], int n) {}
// 240 Check that value already exist value? if not return 0, else return 1
int isExistValue(int arr[], int n, int x) {}
// 241 Check if integer array exists 2 con-consecutive values?
bool isExist2ConConsecutiveValues(int ar[], int n) {}
// 242 Check if integer array exists even number? if not return 0 else return 1
int isExistEvenNumber(int arr[], int n) {}
// 243 Check if integer array exists prime number? if not return 0, true return
// 1
int isExistPrimeNumber(int arr[], int n) {}
// 244 Check if integer array satify properties: Array not contain-
//-perfect number higher than 256. if not return 0, true return 1
int isContainPerfectNumberHigherThan256(int arr[], int n) {}
// 245 Check if integer array is all even number? if true return 1, false return
// 0
int isAllEvenNumbers(int arr[], int n) {}
// 246 Check if float array is symmetric
bool isSymmetric(float arr[], int n) {}
// 247 We define an array with parity, when the sum of two of 2 consecutive
// elements in the array is always odd. Write a function to check
// whether the array a has parity or not
bool isParityArray(int arr[], int n) {}
// 248 Check if integer array is ascending array
bool isAscendingArray(int arr[], int n) {}
// 249 Check if integer array is descending array
int DescendingArray(int arr[], int n) {}
// 250 Please indicate whether the elements in the array form `plus level`
// if yes, please indicate the error d
// Cấp số cộng là dãy số liên tiếp trong đó sự sai khác giữa các số hạng là hằng
// số công sai d
bool isPlusLevel(int arr[], int n) {}
// 251 Check if elements in array whether equal(2 ways)
bool isAllElementsEqualValue(int arr[], int n) {}
// 252 An array is defined as "wave form" when the element i is greater than or
// less than the two sorrounding elements. Write a function to check whether
// the array has a waveform or not?
bool isWaveFormArray(int arr[], int n) {}

// 254 Count the number of values in the array that satify the property:
// greater than all values before it
int CountValuesGreaterThanValuesBeforeIt(int arr[], int n) {}
// KỸ THUẬT SẮP XẾP

// 255 Sort the values in float array ascending
void SortAscending(float arr[], int n) {}
// 256 Sort the values in integer array descending
void SortDescending(int arr[], int n) {}
// 257 Sort the values at odd position ascending, other values keep the same
// value and position
void SortValuesOddPositionAscending(int arr[], int n) {}
// 258 Sort the prime numbers in array ascending, other values keep the same
// value and position
void SortPrimeAscending(int arr[], int n) {}

// 260 array a, b. Please indicate if the array b is the permutation of array of
// not?
bool isPermutationArray(int arr[], int n) {}
// 261 Sort the positive value in float array ascending, negative keep the same
// value and position
void SortPositiveAscending(float arr[], int n) {}
// 262 Sort the even number in integer array ascending, odd number ascending
void SortEvenNumberAscending(int arr[], int n) {}
// 263 Sort the positive in ascending, positive descending.
// The relative position between negative and positive numbers remains constant
void SortPositiveAscendingPositiveDescending(int arr[], int n) {}
// 264 Mix the 2 ascending array into ascending array
void Add2ArrayAscendingIntoAscending(int a[], int na, int b[], int nb, int c[],
                                     int &nc) {}
// 265 2 ascending array, mix 2 arrays into descending array
void Add2ArrayAscendingIntoDescending(int a[], int na, int b[], int nb, int c[],
                                      int &nc) {}
// 267 Write a program to do the following: Input an array of n integers from
// the keyboard so that when finished entering the elements in the array are
// sorted in ascending order(do not sort after import)(preserve import)
void InputArrayAscending(int arr[], int &n) {}
// 268 Create array from a value 0, 1 to make to array has parity
void CreatebParityFroma(int arr[], int n) {}
// ex.6 Input an array A of integers and arrange the array A above according to
// the rules:
//+ Positive numbers at the begining of the array and descending array
//+ Negative numbers at the end of the array and ascending order
void PositiveAtBeginingDesceningNegativeAtEndAscending(int a[], int n) {}
// ex.7 Input an array A of integers and arrange the array A above according to
// the rules:
//+ Even numbers are at the begining of the array and in ascending order
//+ Odd numbers at the end of the array and in descending order
void EvenAtBeginingAscendingOddAtEndDescending(int arr[], int n) {}
// ex.8 Randomly generate an array of integers
// and then sort the array of integer ascending
void RandomlyArray(int arr[], int n) {}
void SortAscending(int arr[], int n) {}
// ex.9 Input an array A of integers and find the 3rd largest element array
int Find3rdElementInArray(int arr[], int n) {}
// ex.10 Advance application of Sorting Algorithm: Giving the sequence of
// integers A as follows: A = {12 2 15 -3 8 5 1 =8 6 0 4 15} Requirements:
// 1. Sort the above array in ascending order => done
// 2. Derive the 3rd largest number in the sequence => done
// 3. Derive the maximum number of the elements in the sequence
// 4. Sort the above sequence in ascending absolute value order
// 5. Arrange the above sequence according to the rule after:
//     5.1 Positive numbers at the begining of the array and descending order
//     5.2 Negative numbers at the end of the array and ascending order
// 6. Arrange the sequence above according to the following rule:
//     6.1 Even numbers at the begining of the array and in ascending order.
//     6.2 Odd numbers at the end of the array and in descending order.
// 3
int FindLargestElement(int arr[], int n) {}
// 4
void SortAbsoluteAscending(int arr[], int n) {}
// 5
void SortPositiveAtBeginDescendNegativeAtEndAscend(int a[], int n) {}
// 6
void EvenAtBeginAscendOddAtDescend(int a[], int n) {}

int main() { return 0; }
