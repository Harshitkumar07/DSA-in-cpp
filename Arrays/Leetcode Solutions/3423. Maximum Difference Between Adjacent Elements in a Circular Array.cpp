** Leetcode Problem 3423 :- **

Given a circular array nums, find the maximum absolute difference between adjacent elements.
Note: In a circular array, the first and last elements are adjacent.

Example 1:
Input: nums = [1,2,4]
Output: 3
Explanation:
Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.

Example 2:
Input: nums = [-5,-10,-5]
Output: 5
Explanation:
The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.

** Code :- **

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int maxDiff = 0;
        for (int i = 0; i < n - 1; i++) {
            maxDiff = max(maxDiff, abs(nums[i] - nums[i + 1]));
        }
        maxDiff = max(maxDiff, abs(nums[n - 1] - nums[0]));
        return maxDiff;
    }
};

** Time Complexity :- **
    
    
Step 1: Iterating Through Adjacent Pairs
The algorithm iterates through the vector nums to compute the maximum absolute difference between adjacent elements.
It runs a loop from index 0 to n - 2, comparing nums[i] and nums[i + 1].

Step 2: Circular Pair Check
After the loop, it also checks the absolute difference between the last and first element: abs(nums[n - 1] - nums[0]).
Let N be the size of the vector nums.

Total Time Complexity :-
Best Case: O(N) → Minimum two elements, all differences checked.
Worst Case: O(N) → All adjacent pairs compared.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
The algorithm uses:
A few integer variables (n, maxDiff, loop counter i).
No additional data structures are used.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Space Complexity)
