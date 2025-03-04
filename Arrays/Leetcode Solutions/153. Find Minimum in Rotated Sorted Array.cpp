** Leetcode Problem 153 :- **

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

** Code :- **

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

** Time Complexity :- **
    
Binary Search on Rotated Sorted Array :
The algorithm applies binary search to find the minimum element in a rotated sorted array.
In each iteration:
It calculates mid = left + (right - left) / 2 in O(1) time.
It checks if nums[mid] > nums[right] and adjusts the search range.
The search space is reduced by half in each step.
Since binary search runs in O(log n) time complexity, the total time complexity is:
Total Time Complexity :
Best Case: O(1) → If the array is already sorted and not rotated, only one comparison is needed.
Worst Case: O(log n) → The search continues until the search space reduces to one element.
Overall: O(log n) (Logarithmic Time Complexity)

** Space Complexity :- **
    
In-Place Computation :
The function modifies no extra data structures.
It uses only a few integer variables (left, right, mid).
Total Space Complexity :
O(1) (Constant Space)
