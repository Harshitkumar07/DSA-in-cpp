** Leetcode Problem 856 :- **

Given a balanced parentheses string s, return the score of the string.
The score of a balanced parentheses string is based on the following rule:
"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

Example 1:
Input: s = "()"
Output: 1

Example 2:
Input: s = "(())"
Output: 2

Example 3:
Input: s = "()()"
Output: 2

** Code :- **

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for (char c : s) {
            if (c == '(') {
                st.push(-1);
            } else {
                int score = 0;
                while (st.top() != -1) {
                    score += st.top();
                    st.pop();
                }
                st.pop();
                if (score == 0) {
                    st.push(1);
                } else {
                    st.push(score * 2);
                }
            }
        }
        int totalScore = 0;
        while (!st.empty()) {
            totalScore += st.top();
            st.pop();
        }
        return totalScore;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the String
The algorithm iterates through the input string s, processing each character once.
If c == '(', it pushes -1 onto the stack.
If c == ')', it pops elements from the stack to calculate the score.
Each element is pushed onto the stack once and popped at most once.
The total operations performed are O(N), where N is the length of s.

Total Time Complexity :
Best Case: O(N) → If s is simple like "()", each character is processed once.
Worst Case: O(N) → If s is deeply nested like "((((()))))", each character is still pushed and popped once.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Stack
The stack stores scores and markers (-1 for ().
In the worst case (deeply nested parentheses like "(((((())))))"), the stack holds N elements, requiring O(N) space.

Total Space Complexity :
Best Case: O(1) → If s is balanced and short, stack usage is minimal.
Worst Case: O(N) → If s is deeply nested, the stack stores all elements.
Overall: O(N) (Linear Space Complexity in the Worst Case)
