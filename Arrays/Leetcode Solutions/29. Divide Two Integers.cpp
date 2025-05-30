** Leetcode Problem 29 :- **

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.
Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. 
For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

** Code :- **

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool isPos = (dividend >= 0) == (divisor >= 0);
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long ans = 0;
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;
            while (a >= (temp + temp)) {
                temp += temp;
                multiple += multiple;
            }
            a -= temp;
            ans += multiple;
        }
        if (!isPos) {
            ans = -ans;
        }
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};

** Time Complexity :- **
    
Step 1: Edge Case Check
The check for dividend == INT_MIN && divisor == -1 is O(1).

Step 2: Convert to Positive Long Long
Absolute value conversion is O(1).

Step 3: Main Division Logic (Bit Manipulation)
The inner loop doubles temp and multiple each time until temp + temp > a. This behaves like a binary search in terms of how many times it loops.
For each iteration of the outer loop, a is reduced by at least half of its remaining value.
So, both loops together execute in O(log N) time, where N = dividend.

Total Time Complexity :-
Best Case: O(log N)
Worst Case: O(log N)
Overall: O(log N) (Binary Search-like Division)

** Space Complexity :- **
    
Uses a constant number of variables (a, b, temp, multiple, ans, etc.).

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Auxiliary Space)
