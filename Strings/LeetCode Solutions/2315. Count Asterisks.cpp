** Leetcode Problem 2315 :- **

You are given a string s, where every two consecutive vertical bars '|' are grouped into a pair.
In other words, the 1st and 2nd '|' make a pair, the 3rd and 4th '|' make a pair, and so forth.
Return the number of '*' in s, excluding the '*' between each pair of '|'.
Note that each '|' will belong to exactly one pair.

Example 1:
Input: s = "l|*e*et|c**o|*de|"
Output: 2
Explanation: The considered characters are underlined: "l|*e*et|c**o|*de|".
The characters between the first and second '|' are excluded from the answer.
Also, the characters between the third and fourth '|' are excluded from the answer.
There are 2 asterisks considered. Therefore, we return 2.

Example 2:
Input: s = "iamprogrammer"
Output: 0
Explanation: In this example, there are no asterisks in s. Therefore, we return 0.

Example 3:
Input: s = "yo|uar|e**|b|e***au|tifu|l"
Output: 5
Explanation: The considered characters are underlined: "yo|uar|e**|b|e***au|tifu|l". There are 5 asterisks considered. Therefore, we return 5.

** Code :- **

class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool bars = false;
        for (char ch : s) {
            if (ch == '|') {
                bars = !bars;
            } else if (ch == '*' && !bars) {
                count++;
            }
        }
        return count;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the String
The algorithm iterates once through the entire input string s.

For each character:
If it is a pipe (|), it toggles a boolean flag.
If it is an asterisk (*) and not between bars, it increments a counter.
All operations inside the loop are constant time.

Total Time Complexity :-
O(n), where n is the length of the input string s.

** Space Complexity :- **
    
Step 1: Variables Used
A few variables are used:int count for counting asterisks.
bool bars to track if we're between bars.
No additional data structures are used.

Total Space Complexity :-
O(1) — constant space.
