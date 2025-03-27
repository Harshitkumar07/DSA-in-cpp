** Leetcode Problem 32 :- **

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0

** Code :- **

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }
        return maxlen;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the String
The algorithm processes each character in s exactly once.
If s[i] == '(', its index is pushed onto the stack.
If s[i] == ')', the top element is popped from the stack.
The i - st.top() operation runs in O(1) time for each iteration.
Since each character is pushed and popped at most once, the total operations are O(N), where N is the length of s.

Total Time Complexity :-
Best Case: O(N) → If s is already valid or empty, we traverse it once.
Worst Case: O(N) → If s is a long sequence of ( and ), we process each character once.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **

Step 1: Stack Usage
The stack stores indices of unmatched '(' characters.
In the worst case (if s consists entirely of '('), the stack holds N elements, requiring O(N) space.

Total Space Complexity :-
Best Case: O(1) → If s is balanced and has no need for stack storage.
Worst Case: O(N) → If s is all '(', the stack stores all indices.
Overall: O(N) (Linear Space Complexity in the Worst Case)
