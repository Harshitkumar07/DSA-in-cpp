** Leetcode Problem 396 :- **

You are given an integer array nums of length n.
Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:
F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).
The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: nums = [4,3,2,6]
Output: 26
Explanation:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.

Example 2:
Input: nums = [100]
Output: 0

** Code :- **

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long int sum = 0, org = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            org += i * nums[i];
        }
        long int Max = org;
        for (int i = n - 1; i >= 0; i--) {
            org += sum - (nums[i] * n);
            Max = max(org, Max);
        }
        return Max;
    }
};

** Time Complexity :- **
    
Initial Computation of sum and org (F(0)) :
The first for loop calculates :
sum (sum of all elements in nums).
org (F(0), the value of the rotation function at index 0).
This loop runs O(n) times.
Iterating Through Rotations :
The second for loop updates org for each rotation using the formula: F(k)=F(k−1)+sum−n×nums[n−k]
This loop also runs O(n) times.
Total Time Complexity :
Best Case: O(n) → The list is small or already optimized.
Worst Case: O(n) → Both loops execute fully.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Computation :
The algorithm uses only a few integer variables (sum, org, Max, n, and loop variables).
No extra data structures or recursion are used.
Total Space Complexity :
O(1) (Constant Space)
