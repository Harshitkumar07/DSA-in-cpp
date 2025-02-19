** Leetcode Problem 3364 :- **

You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0.
Return the minimum sum of such a subarray. If no such subarray exists, return -1.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [3, -2, 1, 4], l = 2, r = 3
Output: 1
Explanation:
The subarrays of length between l = 2 and r = 3 where the sum is greater than 0 are:
[3, -2] with a sum of 1
[1, 4] with a sum of 5
[3, -2, 1] with a sum of 2
[-2, 1, 4] with a sum of 3
Out of these, the subarray [3, -2] has a sum of 1, which is the smallest positive sum. Hence, the answer is 1.

Example 2:
Input: nums = [-2, 2, -3, 1], l = 2, r = 3
Output: -1
Explanation:
There is no subarray of length between l and r that has a sum greater than 0. So, the answer is -1.

Example 3:
Input: nums = [1, 2, 3, 4], l = 2, r = 4
Output: 3
Explanation:
The subarray [1, 2] has a length of 2 and the minimum sum greater than 0. So, the answer is 3.

** Code :- **

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i], sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if ((j - i + 1) >= l && (j - i + 1) <= r) {
                    if (sum > 0) {
                        ans = min(ans, sum);
                    }
                }
                if ((j - i + 1) > r)
                    break;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

** Time Complexity :- **
    
Outer Loop (i from 0 to nums.size() - 1) :
This loop iterates n times, where n is the size of nums.
Inner Loop (j from i to nums.size() - 1) :
In the worst case, this loop runs n - i times for each value of i.
The total number of iterations over all values of i forms a nested loop, resulting in a quadratic time complexity.
The sum calculation and condition checks inside the inner loop take O(1) time per iteration.
Total Time Complexity :
Since we iterate through all pairs (i, j), the worst-case scenario results in O(n²) time complexity.

** Space Complexity :- **
    
Auxiliary Variables :
The algorithm uses only a few integer variables (ans, curr, sum, i, j), which require O(1) space.
No additional data structures are used.
In-Place Computation :
Since all calculations are performed directly on the input array nums without using extra storage, no additional space is required.
Total Space Complexity :
As only O(1) extra space is used, the space complexity remains O(1).
