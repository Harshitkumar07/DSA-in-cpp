** Leetcode Problem 844 :- **

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

** Code :- **

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        for (char ch : s) {
            if (ch == '#') {
                if (!st1.empty()) {
                    st1.pop();
                }
            } else {
                st1.push(ch);
            }
        }
        for (char ch : t) {
            if (ch == '#') {
                if (!st2.empty()) {
                    st2.pop();
                }
            } else {
                st2.push(ch);
            }
        }
        return st1 == st2;
    }
};

** Time Complexity :- **
    
Step 1: Processing Strings s and t Using a Stack
The algorithm iterates through s and processes each character:
If it is '#', it pops from the stack (if not empty).
Otherwise, it pushes the character onto the stack.
The same process is repeated for t.
Since each character is pushed and popped at most once, this step takes O(N) + O(M) = O(N + M), where N and M are the lengths of s and t.
Step 2: Comparing Stacks
The final comparison of stacks takes O(min(N, M)), but in the worst case, it is O(N + M).

Total Time Complexity :
Best Case: O(N + M) → If s and t are already equal without backspaces, we still traverse them once.
Worst Case: O(N + M) → If all characters are non-matching, we fully process both strings.
Overall: O(N + M) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Stacks
The stacks st1 and st2 store characters that are not removed by '#'.
In the worst case (if there are no '#' characters), each stack holds all N and M characters, requiring O(N) + O(M) = O(N + M) space.

Total Space Complexity :
Best Case: O(1) → If all characters are removed via '#', the stacks remain empty.
Worst Case: O(N + M) → If no '#' characters exist, both stacks store all characters.
Overall: O(N + M) (Linear Space Complexity in the Worst Case)
