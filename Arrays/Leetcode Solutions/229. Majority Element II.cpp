** Leetcode Problem 229 :- **

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]

** Code :- **

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        unordered_map<int, int> map;
        vector<int> ans;
        for (auto num : nums) {
            map[num]++;
        }
        for (auto num : map) {
            if (num.second > n) {
                ans.push_back(num.first);
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Counting Element Frequencies (map[num]++)
The function iterates through the nums array once, storing counts in an unordered_map.
This takes O(n) time.
Step 2: Finding Majority Elements (num.second > n)
The function iterates through all unique elements stored in map.
In the worst case (all elements are unique), this takes O(n) time.
Total Time Complexity :
Best Case: O(n) → If all elements are the same, only one entry exists in map.
Worst Case: O(n) → If all elements are unique, we iterate over nums and then the map.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storing Counts in unordered_map
The map stores at most n unique elements, requiring O(n) space in the worst case.
Step 2: Storing Majority Elements in ans
At most two elements can satisfy count > n / 3, leading to O(1) space.
Total Space Complexity :
O(n) (For HashMap Storage)
