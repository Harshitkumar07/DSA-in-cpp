/*
Problem Statement:
Find the maximum element in an array using recursion.

Approach:
Base Case:
If the array has only one element, return that element.

Recursive Case:
Return the maximum of the first element and the maximum of the rest of the array.

Code -
*/

#include<iostream>
using namespace std;

int findMax(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    return max(arr[n - 1], findMax(arr, n - 1));
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Maximum element: " << findMax(arr, n) << endl;
    return 0;
}
/*
Time Complexity:
 The time complexity is O(n) as each element is visited once.

Space Complexity:
 The space complexity is O(n) for the recursion stack.

Example Inputs and Outputs:
1. Input: Enter number of elements: 5
          Enter elements: 3
          9
          5
          6
          2
   Output: Maximum element in the array: 9

2. Input: Enter number of elements: 4
          Enter elements: 3
          1
          3
          5
   Output: Maximum element in the array: 5

*/
