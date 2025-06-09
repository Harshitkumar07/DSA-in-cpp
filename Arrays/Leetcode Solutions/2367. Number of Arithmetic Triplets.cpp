** Leetcode Problem 2367 :- **

You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.

Example 1:
Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 

Example 2:
Input: nums = [4,5,6,7,8,9], diff = 2
Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.

** Code :- **

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

** Time Complexity :- **

Step 1: Triple Nested Loops
The algorithm uses three nested loops to iterate through all possible triplets (i, j, k) where i < j < k.

For each triplet, it checks:
If nums[j] - nums[i] == diff
And if nums[k] - nums[j] == diff

Let N be the size of the nums vector.
The outer loop runs N times.
The middle loop runs up to N - i - 1 times.
The inner loop runs up to N - j - 1 times.
In total, the number of iterations is proportional to the number of combinations of 3 elements from N:
C(N, 3) = N * (N - 1) * (N - 2) / 6

Total Time Complexity :-
Best Case: O(N³) → All triplets are checked regardless of data distribution.
Worst Case: O(N³) → No early termination or pruning.
Overall: O(N³) (Cubic Time Complexity)

** Space Complexity :- **

The algorithm uses a single integer variable count to store the number of valid triplets.
No additional data structures are used.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Space Complexity)
