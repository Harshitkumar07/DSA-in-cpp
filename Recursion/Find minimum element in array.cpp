/*
Problem Statement:
Find the minimum element in an array using recursion.

Approach:
Base Case:
If the array has only one element, return that element.

Recursive Case:
Return the minimum of the first element and the minimum of the rest of the array.

Code -
*/

#include<iostream>
using namespace std;

int findMin(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    return min(arr[n - 1], findMin(arr, n - 1));
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Minimum element: " << findMin(arr, n) << endl;
    return 0;
}

/*
Time Complexity:
 The time complexity is O(n) as each element is visited once.

Space Complexity:
 The space complexity is O(n) for the recursion stack.

Example Inputs and Outputs:
1. Input: Enter number of elements: 5
          Enter elements: 5
          3
          4
          2
          1
   Output: Minimum element in the array: 1

2. Input: Enter number of elements: 4
          Enter elements: 7
          5
          9
          2
   Output: Minimum element in the array: 2
*/
