** Leetcode Problem 20 :- **

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

** Code :- **

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                if ((st.top() == '(' && c == ')') ||
                    (st.top() == '[' && c == ']') ||
                    (st.top() == '{' && c == '}')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the String
The algorithm iterates through the input string s, character by character.
For each character:
If it is an opening bracket ((, {, [), it is pushed onto a stack.
If it is a closing bracket (), }, ]), the algorithm checks the top of the stack:
If the top contains a matching opening bracket, it is popped.
Otherwise, the function returns false immediately.
If the stack is empty when encountering a closing bracket, the function returns false.
Since each character is processed once, either being pushed or popped, the total number of operations is at most O(N).

Total Time Complexity :
Best Case: O(N) → If the input is valid and perfectly balanced, we still iterate through the entire string once.
Worst Case: O(N) → If the input contains only opening brackets (e.g., "(((([[[[{{{{"), we push all characters onto the stack before reaching the end.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Stack Usage
A stack is used to store unmatched opening brackets.
The maximum size of the stack occurs when all characters are opening brackets (e.g., "(((([[[[{{{{"), meaning the stack will hold O(N) elements.
If the input is perfectly balanced (e.g., "(){}[]"), elements are pushed and popped immediately, keeping the stack size minimal.

Total Space Complexity :
Best Case: O(1) → If the input is balanced, the stack never grows beyond a few elements.
Worst Case: O(N) → If the input consists only of opening brackets, the stack stores all characters.
Overall: O(N) (Linear Space Complexity in the Worst Case)
