** Leetcode Problem 678 :- **

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

** Code :- **

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, st2;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else if (!st2.empty()) {
                    st2.pop();
                } else {
                    return false;
                }
            } else {
                st2.push(i);
            }
        }
        while (!st.empty() && !st2.empty()) {
            if (st.top() > st2.top())
                return false;
            st.pop();
            st2.pop();
        }
        return st.empty();
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the String
The algorithm iterates through the input string s, processing each character once.
If the character is:
'(': It is pushed onto stack st (tracking open brackets).
')':
If an '(' exists in st, it is popped.
Otherwise, if a '*' exists in stack st2, it is popped.
If neither is available, the function returns false.
'*': It is pushed onto stack st2 (tracking wildcard positions).
Each character is processed once, so this step takes O(N).

Step 2: Resolving Remaining Open Brackets Using Wildcards
If there are unmatched '(' in st, we attempt to match them with '*' in st2.
If an unmatched '(' appears after a '*' (i.e., st.top() > st2.top()), a valid sequence is not possible, and we return false.
Since each element is processed at most once, this step also runs in O(N).

Total Time Complexity :
Best Case: O(N) → If the string is already valid, we simply traverse it once.
Worst Case: O(N) → If every character is processed fully through both stacks, we still perform O(N) operations.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Stacks
The stack st stores indices of '('.
The stack st2 stores indices of '*'.
In the worst case (if the string consists entirely of '(' and '*'), both stacks hold O(N) elements.

Total Space Complexity :
Best Case: O(1) → If the string is already balanced, stack usage is minimal.
Worst Case: O(N) → If many unmatched brackets or wildcards exist, we store N elements.
Overall: O(N) (Linear Space Complexity in the Worst Case)
