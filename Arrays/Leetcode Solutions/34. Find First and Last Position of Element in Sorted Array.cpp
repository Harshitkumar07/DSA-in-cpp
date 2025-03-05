** Leetcode Problem 34 :- **

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

** Code :- **

class Solution {
public:
    int findFirstPos(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int firstPos = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                firstPos = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return firstPos;
    }
    int findLastPos(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int lastPos = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                lastPos = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return lastPos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        ans[0] = findFirstPos(nums, target);
        ans[1] = findLastPos(nums, target);
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Finding the First Position (findFirstPos)
Uses binary search to find the first occurrence of target.
Each iteration halves the search space.
Runs in O(log n) time.
Step 2: Finding the Last Position (findLastPos)
Also uses binary search to find the last occurrence of target.
Runs in O(log n) time.
Total Time Complexity :
Best Case: O(log n) → If the array is small or the target is found quickly.
Worst Case: O(log n) + O(log n) = O(log n) → Both searches take the maximum number of iterations.
Overall: O(log n) (Logarithmic Time Complexity)

** Space Complexity :- **
    
In-Place Computation :
The function modifies no extra data structures.
It only uses a few integer variables (left, right, mid, firstPos, lastPos).
The result vector ans is of fixed size (2 elements) → O(1) space.
Total Space Complexity :
O(1) (Constant Space)
