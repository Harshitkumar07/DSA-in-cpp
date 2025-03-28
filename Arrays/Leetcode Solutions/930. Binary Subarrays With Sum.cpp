** Leetcode Problem 930 :- **

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15

** Code :- **

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> map;
        map[0] = 1;
        int currSum = 0, ans = 0;
        for (int num : nums) {
            currSum += num;
            if (map.find(currSum - goal) != map.end()) {
                ans += map[currSum - goal];
            }
            map[currSum]++;
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the Array
The algorithm iterates through nums, processing each element once.
At each step, it updates currSum and checks if currSum - goal exists in the unordered_map.
Both updating currSum and checking the map take O(1) time per iteration.
Since each element is processed once, the total operations are O(N), where N is the size of nums.

Total Time Complexity :-
Best Case: O(N) → If all elements are 0 or 1, we still traverse the array once.
Worst Case: O(N) → Even if the array contains large values, we process each element once.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Hash Map
The unordered_map map stores prefix sums.
In the worst case (when all prefix sums are unique), the map holds O(N) entries.

Total Space Complexity :-
Best Case: O(1) → If the same prefix sum appears frequently, the map size is small.
Worst Case: O(N) → If all prefix sums are unique, the map stores N values.
Overall: O(N) (Linear Space Complexity in the Worst Case)
