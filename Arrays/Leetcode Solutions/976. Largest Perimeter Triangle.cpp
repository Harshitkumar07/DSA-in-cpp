** Leetcode Problem 976 :- **

Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. 
If it is impossible to form any triangle of a non-zero area, return 0.

Example 1:
Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.

Example 2:
Input: nums = [1,2,1,10]
Output: 0
Explanation: 
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.

** Code :- **

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i + 1] + nums[i + 2] > nums[i]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};

** Time Complexity :- **
    
    
Step 1: Sorting the Array
The array nums is sorted in descending order using sort(nums.begin(), nums.end(), greater<int>()).
Let N be the size of the array.
Sorting takes O(N log N) time.

Step 2: Finding a Valid Triangle
The algorithm iterates through the sorted array up to index N - 3.
For each triplet (i, i+1, i+2), it checks if nums[i+1] + nums[i+2] > nums[i] (triangle inequality).
If such a triplet is found, the perimeter is returned immediately.
This loop runs at most O(N) times.

Total Time Complexity :- 
Best Case: O(N log N) → Dominated by sorting.
Worst Case: O(N log N) → All triplets checked, no valid triangle.
Overall: O(N log N) (Log-Linear Time Complexity)

** Space Complexity :- **

The algorithm performs in-place sorting and uses a few integer variables.
No additional data structures are created.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Space Complexity)
