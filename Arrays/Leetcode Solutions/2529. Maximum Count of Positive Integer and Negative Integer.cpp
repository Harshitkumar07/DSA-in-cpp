** Leetcode Problem 2529 :- **

Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.

Example 1:
Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.

Example 2:
Input: nums = [-3,-2,-1,0,0,1,2]
Output: 3
Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.

Example 3:
Input: nums = [5,20,66,1314]
Output: 4
Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.

** Code :- **

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount = 0, negCount = 0;
        for (int num : nums) {
            if (num > 0) {
                posCount++;
            } else if (num < 0) {
                negCount++;
            }
        }
        return max(posCount, negCount);
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the Array
The algorithm iterates through the input array nums, processing each element once.
For each element:
If it is positive, posCount is incremented.
If it is negative, negCount is incremented.
Zeroes are ignored.
Since each element is checked exactly once, the total number of operations is O(N), where N is the size of nums.

Total Time Complexity :
Best Case: O(N) → Regardless of the input, the algorithm always iterates through the array once.
Worst Case: O(N) → Even if all elements are the same (e.g., all positive or all negative), we still traverse the entire array.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Variable Usage
The algorithm uses only two integer variables: posCount and negCount.
No extra data structures (like arrays or stacks) are used.
Space usage remains constant regardless of the size of the input array.

Total Space Complexity :
Best Case: O(1) → Only a few integer variables are used.
Worst Case: O(1) → Space usage does not grow with input size.
Overall: O(1) (Constant Space Complexity)
