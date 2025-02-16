** Leetcode Problem 912 :- **

Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.

** Code :- **

class Solution {
public:
    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        vector<int> L(n1);
        vector<int> R(n2);
        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

** Time Complexity :- **
    
Dividing the Array (Merge Sort Recursion) :
At each step, the array is split into two halves recursively.
The number of divisions follows O(log n) recursion depth.
Merging the Sorted Halves :
The merge() function takes O(n) time to merge two sorted subarrays.
Total Time Complexity :
Each level of recursion requires O(n) time for merging.
Since there are O(log n) levels of recursion, the total time complexity is O(n log n).
Best Case: O(n log n) → Even if the array is already sorted, it will still be divided and merged.
Worst Case: O(n log n) → The algorithm always follows the same divide-and-merge approach.

** Space Complexity :- **
    
Auxiliary Space for Temporary Arrays :
The merge() function creates two temporary arrays (L and R), requiring O(n) extra space.
Recursive Stack Space :
The recursive mergeSort() function uses a stack with a maximum depth of O(log n).
Total Space Complexity :
Best Case: O(n) → The auxiliary arrays dominate space usage.
Worst Case: O(n) → Even with maximum recursion depth, additional space is limited to O(n) due to temporary storage in merge().
