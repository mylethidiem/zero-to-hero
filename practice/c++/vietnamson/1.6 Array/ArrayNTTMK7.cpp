#include <cmath>
#include <iostream>
#define MAX 50
// KỸ THUẬT XỬ LÝ MẢNG CON
void InputArray(int a[], int n) {}
void OutputArray(int a[], int n) {}
// 293 List all subarrays in a one-dimensional array of integers
void ListAllSubarrays(int arr[], int n) {}
// 294 List all sub-arrays of length greater than
// 2 in a one-dimensional array of integers
void ListAllSubarraysLongerThan2(int arr[], int n) {}
// 295 List incrementing subsequences in array
void ListIncrementingSubsequences(int arr[], int n) {}
// 296 List the incrementing subarrays containing the largest value in the array
void ListIncrementingSubarraysLargestValue(int arr[], int n) {}
// 297 Sum each incrementing subarray in a one-dimensional array array of real
// numbers
void SumEachIncrementingSubarrays(float arr[], int n) {}
// 298 Count the number of incremented subarrays of length greater
// than 1 in a one-dimensional array of real numbers
int CountNumberOfIncrementedSubarraysLengthGreaterThan1(float arr[], int n) {}
// 299 List all positive subsequences of length greater than 1 in
// a one-dimensional array of real numbers
void ListAllPositiveSubsequencesLengthGreaterThan1(float arr[], int n) {}
// 300 Count the number of reduced subarrays in a one-dimensional array if real
// numbers
int CountReducedSubarrays(float arr[], int n) {}
// 301 Please tell if array a is a subarray of array b or not
bool isSubarray(int subarray[], int nsub, int arr[], int n) {}
// 302 array a,b. Count the number of occurences of array a in array b
int CountNumberArrayaInArrayb(int a[], int na, int b[], int nb) {}
// 303 Find the longest all-positive subsequnce in the array
// of real numbers
void LongestAllPositiveSubsequence(int arr[], int n, int result[], int r) {}
// 304 one dimensional array of integers and an integer M. Find a subarray
// such that the sum of the elements in the array equals M

void SubArraySumEqualM(int arr[], int n, int M, int result, int r) {}
// XÂY DỰNG MẢNG
// 307 one-dimensional array of integers a. Let's create array b from a
// so that b contains only odd values
void GetOddArrayFromArraya(int a[], int na, int b[], int nb) {}
// 308 one-dimensional array of real numbers a. Create array b from a,
// such that array b contains only negative values
void GetNegativeArrayFromArraya(float a[], int na, float b[], int nb) {}
// 309 one-dimensional array of real numbers a. Let's create array b from a,
// with b[i]=sum of elements adjacent to a[i] in array a
void GetArraybFromArraya309(int a[], int na, int b[], int nb) {}
// 310 Given a one-dimensional array of integers a.
// Create array b from array a,
// such that array b contains only the primes in array a
void GetArrayPrimeFromArraya(int a[], int na, int b[], int nb) {}

// ex.12 Đề thi tốt nghiệp lần 2/267/SBT Thầy NTTMK
//  Write a program to input an array of integers:
//  a> Output the largest element.
//  b> Sort the array ascending.
//  c> Sum the first 5 odd numbers of the array, if the number of elements is
//  odd less than 5, calculate sum of odd numbers of array elements. d> Remove
//  duplicate elements of the array (keep the first element and delete the
//  elements duplicate then). For example: Given array A={4,5,3,5,6,7,8,7}, the
//  result after deletion is A={4,5,3,6,7,8} .
void SortArrayAscending(int a[], int n) {}
int SumFirst5OddNumbers(int a[], int n) {}
void RemoveDuplicate(int a[], int &n) {}

int main() { return 0; }
