** Leetcode Problem 1614 :- **

Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

Example 1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation:
Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3
Explanation:
Digit 3 is inside of 3 nested parentheses in the string.

Example 3:
Input: s = "()(())((()()))"
Output: 3

** Code :- **

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0, currDepth = 0;
        for (char c : s) {
            if (c == '(') {
                currDepth++;
                maxDepth = max(maxDepth, currDepth);
            } else if (c == ')') {
                currDepth--;
            }
        }
        return maxDepth;
    }
};

** Time Complexity :- **
    
Step 1: Single Pass Through the String
The algorithm iterates over each character in the string s.
When it encounters '(', it increments the current depth and updates the maximum depth if necessary.
When it encounters ')', it decrements the current depth.
All other characters are ignored.
Let N be the length of the string s.
Each character is processed exactly once.

Total Time Complexity :-
Best Case: O(N) → Minimal parentheses; still needs to scan the entire string.
Worst Case: O(N) → Many nested parentheses.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
The algorithm uses two integer variables: currDepth and maxDepth.
No additional data structures are used.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Space Complexity)
