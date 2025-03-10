** Leetcode Problem 8 :- **

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result. 

Example 1:
Input: s = "42"
Output: 42
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^

Example 2:
Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:
Input: s = "1337c0d3"
Output: 1337
Explanation:
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:
Input: s = "0-1"
Output: 0
Explanation:
Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^

Example 5:
Input: s = "words and 987"
Output: 0
Explanation:
Reading stops at the first non-digit character 'w'.

** Code :- **

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long ans = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+')
            i++;
        while (i < s.length()) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT_MAX && sign == -1) {
                    return INT_MIN;
                } else if (ans > INT_MAX && sign == 1) {
                    return INT_MAX;
                }
                i++;
            } else {
                return ans * sign;
            }
        }
        return (ans * sign);
    }
};

** Time Complexity :- **
    
Step 1: Skipping Leading Whitespaces (while loop)
The function skips leading spaces, taking O(k) time, where k is the number of spaces.
In the worst case, k = n, so O(n).
Step 2: Handling the Sign (if conditions)
Checks for + or - sign in O(1) time.
Step 3: Parsing the Digits (while loop)
The function parses digits until a non-numeric character is encountered.
Since at most n characters are processed, this takes O(n) time.
Step 4: Handling Overflow (if conditions)
Every iteration checks if ans exceeds INT_MAX, which takes O(1) per iteration.
Since this happens inside the digit-processing loop, the overall impact remains O(n).
Total Time Complexity :
Best Case: O(1) → If the string is empty or contains only non-numeric characters.
Worst Case: O(n) → If the string consists of spaces followed by a long sequence of digits.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: In-Place Processing
The function modifies no extra data structures, using only a few integer variables (i, sign, ans).
Total Space Complexity :
O(1) (Constant Space)
