** Leetcode Problem 922 :- **

Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
Return any answer array that satisfies this condition.

Example 1:
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Example 2:
Input: nums = [2,3]
Output: [2,3]

** Code :- **

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 1;
        while (i < n && j < n) {
            if (nums[i] % 2 == 0) {
                i += 2;
            } else if (nums[j] % 2 == 1) {
                j += 2;
            } else {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};

** Time Complexity :- **
    

Iterating Through the Array :
The algorithm runs a while loop that processes each element at most once.
The i pointer increments by 2 when it finds a correctly placed even number.
The j pointer increments by 2 when it finds a correctly placed odd number.
Swapping occurs only when a misplaced number is found.
Since each element is visited once, the overall time complexity is O(n).
Swapping Elements :
Swapping two elements is O(1) and does not affect the overall complexity.
Total Time Complexity :
Best Case: O(n) → If the array is already sorted, each element is checked once.
Worst Case: O(n) → Every misplaced element is swapped, but each element is still visited once.

** Space Complexity :- **
    
In-Place Modifications :
The algorithm modifies the input array directly without using extra space.
Total Space Complexity :
O(1) → No additional data structures are used.
The function only uses a few integer variables (i, j, n).
