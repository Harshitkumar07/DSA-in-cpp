/*
Problem Statement:
Search for a target value in a sorted array using recursive binary search.

Approach:
1. Base Case:
  If the search range becomes invalid (i.e., start > end), return -1, indicating that the target is not found.

2. Recursive Case:

    Calculate the middle index, mid = (start + end) / 2.
    If the middle element matches the target, return the index mid.
    If the target is less than the middle element, search the left half (start to mid-1).
    If the target is greater than the middle element, search the right half (mid+1 to end).
*/
#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target) {
    if (start > end)
        return -1;  // Base case: target not found

    int mid = start + (end - start) / 2;  // Prevent overflow
    if (arr[mid] == target)
        return mid;  // Target found
    else if (arr[mid] > target)
        return binarySearch(arr, start, mid - 1, target);  // Search left half
    else
        return binarySearch(arr, mid + 1, end, target);  // Search right half
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter the target number: ";
    cin >> target;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found in the array." << endl;
    return 0;
}
/*
◾ Time Complexity: O(log(n))
  Each recursive call divides the problem size by 2, leading to a logarithmic number of calls.

◾ Space Complexity: O(log(n))
  The depth of the recursion is log(n), so the space used by the stack is logarithmic.

Example Inputs and Outputs:
1. Input: arr = [1, 3, 5, 7, 9, 11, 13], target = 7
  Output: Target found at index: 3

2. Input: arr = [1, 3, 5, 7, 9, 11, 13], target = 4
  Output: Target not found in the array.
*/
