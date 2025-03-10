** Leetcode Problem 1021 :- **

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

** Code :- **

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        for (char c : s) {
            if (c == '(') {
                if (!st.empty()) {
                    ans += c;
                }
                st.push(c);
            } else {
                st.pop();
                if (!st.empty()) {
                    ans += c;
                }
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the String (for loop)
The function iterates over the input string once, processing each character in O(1) time.
This results in O(n) time complexity.
Step 2: Stack Operations (st.push() and st.pop())
Each push and pop operation on the stack runs in O(1) time.
Since every parenthesis is pushed and popped once, this takes O(n) time.
Total Time Complexity :
Best Case: O(n) → If the string contains no outer parentheses to remove.
Worst Case: O(n) → If the entire string is processed.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Stack Storage (st)
The stack stores at most O(n) characters in the worst case (if all parentheses are nested).
However, in a well-formed sequence, only O(1) space is used on average.
Step 2: Output String (ans)
The output string stores at most O(n) characters.
Total Space Complexity :
O(n) (For Output Storage and Stack in Worst Case)
