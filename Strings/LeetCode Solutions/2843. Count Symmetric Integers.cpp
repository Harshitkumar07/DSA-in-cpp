** Leetcode Problem 2843 :- **

You are given two positive integers low and high.
An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. 
Numbers with an odd number of digits are never symmetric.
Return the number of symmetric integers in the range [low, high].

Example 1:
Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.

Example 2:
Input: low = 1200, high = 1230
Output: 4
Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.

** Code :- **

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; ++num) {
            string str = to_string(num);
            int len = str.length();
            if (len % 2 != 0)
                continue;
            int half = len / 2;
            int leftSum = 0, rightSum = 0;
            for (int i = 0; i < half; i++) {
                leftSum += str[i] - '0';
            }
            for (int i = half; i < len; i++) {
                rightSum += str[i] - '0';
            }
            if (leftSum == rightSum) {
                count++;
            }
        }
        return count;
    }
};

** Time Complexity :- **
    
    
Step 1: Iterating from low to high
The loop runs for every integer from low to high, inclusive.
This results in (high - low + 1) iterations.

Step 2: Processing Each Number
For each number:
Convert to string → O(log₁₀(num)) ≈ O(d), where d is the number of digits.

If the number has an even number of digits:
Split into two halves and calculate the digit sum of each → takes O(d) time.
Since the number of digits d is at most 6 (for inputs ≤ 999999), the digit processing per number can be considered constant time in practice.

Total Time Complexity :-
Best Case: O(n), where n = high - low + 1 (if all numbers are odd-digit and skipped).
Worst Case: O(n × d) → With d bounded (max 6), this is still linear relative to the range size.
Overall: O(high - low + 1) = O(n)

** Space Complexity :- **
    
Step 1: String Conversion
Each number is converted to a string, requiring O(d) temporary space, where d is the number of digits (≤ 6).

Step 2: Variables
Only a few integer variables are used to store sums and counters.

Total Space Complexity :-
Best Case: O(1) 
Worst Case: O(1), since no data structures scale with input size.
Overall: O(1) (Constant space)
