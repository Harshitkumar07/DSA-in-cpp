** Leetcode Problem 1004 :- **

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's. 

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

** Code :- **

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxLen = 0, zeroCount = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) 
                zeroCount++;
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

** Time Complexity :- **
    
Step 1: Expanding the Window (right Pointer Moves Right)
The algorithm iterates through nums once using the right pointer.
This takes O(n) time.
Step 2: Shrinking the Window (left Pointer Moves Right)
When zeroCount > k, the left pointer moves right until the condition is satisfied.
Since each element is processed at most once, this also takes O(n) time.
Total Time Complexity :
Best Case: O(n) → If k is large enough to allow flipping all zeros, left rarely moves.
Worst Case: O(n) → If k = 0, every zero causes left to move frequently.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Computation :
The function modifies no extra data structures.
Only a few integer variables (left, right, maxLen, zeroCount) are used.
Total Space Complexity :
O(1) (Constant Space)
