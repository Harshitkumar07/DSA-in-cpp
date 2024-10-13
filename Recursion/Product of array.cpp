/*
Problem Statement:
Calculate the product of all elements in an array using recursion.

Approach:
1. Base Case:
   If the array size is 0, return 1 (neutral element for multiplication).

2. Recursive Case:
   Return the first element multiplied by the product of the rest of the array.

Code -
*/
#include <iostream>
using namespace std;

int productArray (int arr[], int n)
{
    if (n == 0) return 1;  // Base case
    return arr[0] * productArray (arr + 1, n - 1); // Recursive case
}

int main()
{
    int arr[] = {2, 3, 5, 8, 6, 4};
    int n = sizeof (arr) / sizeof (arr[0]);
    cout << "Product of elements in the array: " << productArray (arr, n) << endl;
    return 0;
}
/*

◾ Time Complexity: O(n)
  Each element in the array is multiplied once, resulting in n recursive calls.

◾ Space Complexity: O(n)
  The recursion depth is proportional to the number of elements in the array.

Example inputs and outputs-
1. Input: arr[] = {1, 2, 3, 4, 5}
   Output: 120

2. Input: arr[] = {2, 3, 5, 8, 6, 4}
   Output: 5760
*/
