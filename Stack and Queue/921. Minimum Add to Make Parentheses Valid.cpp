** Leetcode Probelm 921 :- **

A parentheses string is valid if and only if:
It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Example 1:
Input: s = "())"
Output: 1

Example 2:
Input: s = "((("
Output: 3

** Code :- **

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    count++;
                } else {
                    st.pop();
                }
            }
        }
        return count + st.size();
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the String
The algorithm iterates through s character by character.
Each character is either:
Pushed onto the stack if it is '('.
Popped from the stack if it is ')' and a matching '(' exists.
Counted as an extra closing bracket if no matching '(' exists.
Since each character is processed once, the total number of operations is O(N).

Total Time Complexity :
Best Case: O(N) → Even in the most balanced case, we iterate through the string once.
Worst Case: O(N) → If all characters are '(', we traverse the entire string and store everything in the stack.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Stack
The stack stores unmatched '(' characters.
In the worst case (if s contains only '('), the stack holds N elements, requiring O(N) space.
Step 2: Storage for Count Variable
The count variable stores unmatched ')' characters, requiring O(1) space.

Total Space Complexity :
Best Case: O(1) → If the string is already balanced, the stack remains empty.
Worst Case: O(N) → If all characters are '(', the stack stores all of them.
Overall: O(N) (Linear Space Complexity in the Worst Case)
