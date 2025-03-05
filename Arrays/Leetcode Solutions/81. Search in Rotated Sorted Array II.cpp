** Leetcode Problem 81 :- **

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible. 

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

** Code :- **

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) 
                return true;
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

** Time Complexity :- **
    
Step 1: Binary Search with Duplicates Handling
The algorithm performs a modified binary search on a rotated sorted array that may contain duplicates.
In each iteration:
It calculates mid = left + (right - left) / 2 in O(1) time.
If nums[mid] == target, it returns true immediately (O(1) in best case).
If nums[left] == nums[mid] == nums[right], it reduces the search space by incrementing left and decrementing right.
Worst case: If most elements are duplicates, the search space reduces only by one element per iteration, leading to O(n) worst-case complexity.
Otherwise, it performs regular binary search logic, reducing the search space by half in each step (O(log n) in the best and average cases).
Total Time Complexity :
Best Case: O(1) → If target is found at mid in the first iteration.
Average Case: O(log n) → If the array is well-balanced with few duplicates, normal binary search applies.
Worst Case: O(n) → If all elements are duplicates except one, left++ and right-- reduce search space linearly.
Overall: O(log n) in most cases, but O(n) in worst case when there are too many duplicates.

** Space Complexity :- **

In-Place Computation :
The function does not use extra data structures.
Only a few integer variables (left, right, mid, target) are used.
Total Space Complexity :
O(1) (Constant Space)
