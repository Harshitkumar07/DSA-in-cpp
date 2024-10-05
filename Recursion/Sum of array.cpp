/*
Problem Statement:
Find the sum of elements in an array using recursion.

Approach:
1. Base Case:
   If the array size is 0, the sum is 0.

2. Recursive Case:
   The sum of the array is equal to the first element plus the sum of the rest of the array.

   For an array arr[] of size n, the recursive step is:
   sumArray(arr, n) = arr[0] + sumArray(arr+1, n-1).

Code -  */

#include<iostream>
using namespace std;

int sumOfArray(int arr[], int n) {
    if(n == 0)
        return 0;
    return arr[n - 1] + sumOfArray(arr, n - 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Sum of array: " << sumOfArray(arr, n) << endl;
    return 0;
}

/*
Time Complexity:

 Each element of the array is processed exactly once, making the time complexity linear.
 Time Complexity: O(n) where n is the number of elements in the array.

Space Complexity:

 The recursion depth grows in proportion to the size of the array.
 Space Complexity: O(n)

Example Inputs and Outputs:

1. Input: Enter number of elements: 5
          Enter elements: 5
          3
          7
          6
          2
   Output: Sum of array: 23

2. Input: Enter number of elements: 3
          Enter elements:3
          5
          8
   Output: Sum of array: 16
*/
