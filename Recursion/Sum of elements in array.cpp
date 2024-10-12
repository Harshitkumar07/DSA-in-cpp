/*
Problem Statement:
Calculate the sum of all elements in an array using recursion.

Approach:
1. Base Case:
  If the array size is 0, return 0.

2. Recursive Case:
   Return the first element plus the sum of the rest of the array.

Code -
*/

#include <iostream>
using namespace std;

int sumArray(int arr[], int n) {
    if (n == 0) return 0;  // Base case
    return arr[0] + sumArray(arr + 1, n - 1);  // Recursive case
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of array: "<<endl;
    int arr[n];
    for(int i;i<n;i++){
        cin>>arr[i];
    }
    cout << "Sum of elements in the array: " << sumArray(arr, n) << endl;
    return 0;
}

/*

◾ Time Complexity: O(n)
  The function makes n recursive calls, processing each element once.

◾ Space Complexity: O(n)
  The recursion depth is equal to the size of the array, leading to a space complexity of O(n).

Example Inputs and Outputs:

1. Input: Enter the size of the array: 4
          Enter the elements of array:
          3
          5
          6
          1
   Output: Sum of elements in the array: 15

2. Input: Enter the size of the array: 6
          Enter the elements of array:
          15
          8
          9
          5
          7
          6
   Output: Sum of elements in the array: 60
*/
