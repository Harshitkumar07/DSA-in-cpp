** Leetcode Problem 3024 :- **

You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.
A triangle is called equilateral if it has all sides of equal length.
A triangle is called isosceles if it has exactly two sides of equal length.
A triangle is called scalene if all its sides are of different lengths.
Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.

Example 1:
Input: nums = [3,3,3]
Output: "equilateral"
Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.

Example 2:
Input: nums = [3,4,5]
Output: "scalene"
Explanation: 
nums[0] + nums[1] = 3 + 4 = 7, which is greater than nums[2] = 5.
nums[0] + nums[2] = 3 + 5 = 8, which is greater than nums[1] = 4.
nums[1] + nums[2] = 4 + 5 = 9, which is greater than nums[0] = 3. 
Since the sum of the two sides is greater than the third side for all three cases, therefore, it can form a triangle.
As all the sides are of different lengths, it will form a scalene triangle.

** Code :- **

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums.size() != 3) {
            return "Invalid input";
        }
        int a = nums[0], b = nums[1], c = nums[2];
        if (a + b <= c || b + c <= a || a + c <= b) {
            return "none";
        }
        if (a == b && b == c) {
            return "equilateral";
        } else if (a == b || b == c || a == c) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};

** Time Complexity :- **

Step 1: Input Validation
The check nums.size() != 3 is done in constant time → O(1).

Step 2: Assigning Values
Assigning three integers a, b, and c from the input vector → O(1).

Step 3: Triangle Inequality Check
The conditions:
a + b <= c
b + c <= a
a + c <= b
are constant-time arithmetic comparisons → O(1).

Step 4: Type Determination
Further comparisons to determine triangle type:
Equality checks between a, b, and c → O(1).

Total Time Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Time)

** Space Complexity :- **

Only a few integer variables (a, b, c) and a return string are used.
No auxiliary data structures are created that grow with input size.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Space)
