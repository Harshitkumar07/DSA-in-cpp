** Leetcode Problem 2903 :- **

You are given a 0-indexed integer array nums having length n, an integer indexDifference, and an integer valueDifference.
Your task is to find two indices i and j, both in the range [0, n - 1], that satisfy the following conditions:
abs(i - j) >= indexDifference, and
abs(nums[i] - nums[j]) >= valueDifference
Return an integer array answer, where answer = [i, j] if there are two such indices, and answer = [-1, -1] otherwise. If there are multiple choices for the two indices, return any of them.
Note: i and j may be equal.

Example 1:
Input: nums = [5,1,4,1], indexDifference = 2, valueDifference = 4
Output: [0,3]
Explanation: In this example, i = 0 and j = 3 can be selected.
abs(0 - 3) >= 2 and abs(nums[0] - nums[3]) >= 4.
Hence, a valid answer is [0,3].
[3,0] is also a valid answer.

Example 2:
Input: nums = [2,1], indexDifference = 0, valueDifference = 0
Output: [0,0]
Explanation: In this example, i = 0 and j = 0 can be selected.
abs(0 - 0) >= 0 and abs(nums[0] - nums[0]) >= 0.
Hence, a valid answer is [0,0].
Other valid answers are [0,1], [1,0], and [1,1].

Example 3:
Input: nums = [1,2,3], indexDifference = 2, valueDifference = 4
Output: [-1,-1]
Explanation: In this example, it can be shown that it is impossible to find two indices that satisfy both conditions.
Hence, [-1,-1] is returned.

** Code :- **

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference,
                            int valueDifference) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + indexDifference; j < n; ++j) {
                if (abs(nums[i] - nums[j]) >= valueDifference) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

** Time Complexity :- **

Step 1: Outer Loop (i)
Runs from 0 to n - 1 → O(n)

Step 2: Inner Loop (j)
Starts from i + indexDifference to n - 1
In the worst case, when indexDifference is 1, the inner loop can run up to n - 1 times for each i.

Step 3: Total Work
Worst-case total comparisons:
Upper bounded by the sum of arithmetic progression from indexDifference to n, which is roughly O(n²) in the worst case.

Early Return Optimization :
If a valid pair is found early, the function returns immediately.
Best Case Time Complexity: O(1) (if the first valid pair is at the start)

Total Time Complexity :-
Best Case: O(1)
Worst Case: O(n²)
Overall: O(n²) (Quadratic Time in the Worst Case)

** Space Complexity :- **

A fixed-size vector {i, j} is returned → O(1)
No additional memory usage beyond a few integer variables.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Space)
