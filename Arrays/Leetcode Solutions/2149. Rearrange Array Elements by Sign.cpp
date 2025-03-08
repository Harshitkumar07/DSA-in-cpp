** Leetcode Problem 2149 :- **

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
You should return the array of nums such that the the array follows the given conditions:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Example 1:
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

Example 2:
Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].

** Code :- **

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posIdx = 0, negIdx = 1;
        for (int num : nums) {
            if (num > 0) {
                ans[posIdx] = num;
                posIdx += 2;
            }
        }
        for (int num : nums) {
            if (num < 0) {
                ans[negIdx] = num;
                negIdx += 2;
            }
        }
        return ans;
    }
};

** Time Complexity :- **

Step 1: Iterating Through the Array to Place Positive Numbers
The first for loop iterates through nums and places positive numbers in the correct positions.
This takes O(n) time.
Step 2: Iterating Through the Array to Place Negative Numbers
The second for loop iterates through nums again and places negative numbers in the correct positions.
This also takes O(n) time.
Total Time Complexity
Best Case: O(n) → If the array is already alternating, it still requires scanning.
Worst Case: O(n) → All elements must be repositioned.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Output Array (ans)
A new array ans of size n is created, leading to O(n) space usage.
Step 2: Auxiliary Variables (posIdx, negIdx)
Only a few integer variables (posIdx, negIdx, num) are used, which take O(1) space.
Total Space Complexity :
O(n) (For Output Storage)
