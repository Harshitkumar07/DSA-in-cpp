** Leetcode Problem 2042 :- **

A sentence is a list of tokens separated by a single space with no leading or trailing spaces. Every token is either a positive number consisting of digits 0-9 with no leading zeros, or a word consisting of lowercase English letters.
For example, "a puppy has 2 eyes 4 legs" is a sentence with seven tokens: "2" and "4" are numbers and the other tokens such as "puppy" are words.
Given a string s representing a sentence, you need to check if all the numbers in s are strictly increasing from left to right (i.e., other than the last number, each number is strictly smaller than the number on its right in s).
Return true if so, or false otherwise. 

Example 1:

Input: s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
Output: true
Explanation: The numbers in s are: 1, 3, 4, 6, 12.
They are strictly increasing from left to right: 1 < 3 < 4 < 6 < 12.

Example 2:
Input: s = "hello world 5 x 5"
Output: false
Explanation: The numbers in s are: 5, 5. They are not strictly increasing.

Example 3:
Input: s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
Output: false
Explanation: The numbers in s are: 7, 51, 50, 60. They are not strictly increasing.

** Code :- **

class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if (num <= prev) {
                    return false;
                }
                prev = num;
            }
        }
        return true;
    }
};

** Time Complexity :- **
    
Step 1: Single Pass Through the String
The algorithm iterates through the string s character by character.
On encountering a digit, it enters a nested loop to extract the full number (which may consist of multiple digits).
It then compares the extracted number with the previous one.
Each character in the string is visited only once.
Alphabetic characters are skipped in a single pass.
Digit characters are processed and advanced through in the nested loop.
Let N be the length of the string s.

Total Time Complexity :-
Best Case: O(N) → Few or no digits; minimal numeric processing.
Worst Case: O(N) → Entire string is processed; all characters are digits or part of numbers.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
The algorithm uses a few integer variables (prev, num, i, n) to store numeric values and loop counters.
No additional data structures are used.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Space Complexity)
