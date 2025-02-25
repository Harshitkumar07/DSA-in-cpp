** Leetcode Problem 162 :- **

A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

** Code :- **

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int right = nums.size() - 1, left = 0;
        while (right > left) {
            int mid = (right + left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

** Time Complexity :- **
    
Binary Search for Peak Element :
The algorithm applies binary search to find a peak element. 
In each iteration:
It calculates mid = (left + right) / 2 in O(1) time.
It checks whether nums[mid] > nums[mid + 1] and adjusts the search range.
The search space is reduced by half in each step.
Since binary search runs in O(log n) time complexity, the total time complexity is:
Total Time Complexity :
Best Case: O(1) → If the peak is found immediately (first iteration).
Worst Case: O(log n) → The search continues until the search space reduces to one element.
Overall: O(log n) (Logarithmic Time Complexity)

** Space Complexity :- **
    
In-Place Modifications :
The algorithm modifies no extra data structures.
It uses only three integer variables (left, right, mid).
Total Space Complexity :
O(1) (Constant Space)
