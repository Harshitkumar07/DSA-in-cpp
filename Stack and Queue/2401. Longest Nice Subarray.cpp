** Leetcode Problem 2401 :- **

You are given an array nums consisting of positive integers.
We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
Return the length of the longest nice subarray.
A subarray is a contiguous part of an array.
Note that subarrays of length 1 are always considered nice. 

Example 1:
Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.

Example 2:
Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.

** Code :- **

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        long long curr = 0, ans = INT_MIN, left = 0, right = 0;
        while (right < n) {
            if ((nums[right] & curr) == 0) {
                curr = curr | nums[right];
                ans = max(ans, right - left + 1);
                right++;
            } else {
                curr = curr ^ nums[left];
                left++;
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Using the Two-Pointer (Sliding Window) Approach
The algorithm maintains a sliding window using two pointers: left and right.
The right pointer extends the window while ensuring the bitwise AND condition holds.
If a conflict is found ((nums[right] & curr) != 0), the left pointer moves forward, shrinking the window until the condition is satisfied again.
Each element is added to curr at most once and removed at most once.

Total Time Complexity :
Best Case: O(N) → If all elements form a valid subarray without conflicts, the right pointer moves through the array once.
Worst Case: O(N) → Each element is processed at most twice (once when added, once when removed).
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Variables
The algorithm uses a few integer/long long variables (curr, ans, left, right), requiring O(1) space.
No additional data structures are used.

Total Space Complexity :
Best Case: O(1) → Only a few integer variables are used.
Worst Case: O(1) → Space usage does not depend on input size.
Overall: O(1) (Constant Space Complexity)
