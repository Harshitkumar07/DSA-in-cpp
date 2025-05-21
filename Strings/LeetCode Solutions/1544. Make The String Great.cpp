** Leetcode Problem 1544 :- **

Given a string s of lower and upper case English letters.
A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
Notice that an empty string is also good.

Example 1:
Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".

Example 2:
Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""

Example 3:
Input: s = "s"
Output: "s"

** Code :- **

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && abs(st.top() - c) == 32) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        string ans;
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

** Time Complexity :- **
    
    
Step 1: Iterating Through the String
The function iterates over each character in the input string s, once.

For each character:
It checks the top of the stack.
If the top and current character are the same letter with different cases (i.e., their ASCII difference is 32), it pops the stack (cancels the pair).
Otherwise, it pushes the character onto the stack.
Each character is pushed at most once and popped at most once, so all stack operations combined are O(N).

Step 2: Building the Result
After processing the stack, a loop pops all characters to construct the result string.
This loop runs at most N times (in the worst case when no characters are removed).

Total Time Complexity :-
Best Case: O(N) → Even if all characters cancel early, each character is processed once.
Worst Case: O(N) → No characters cancel, all go into the stack and are processed again while building the result.
Overall: O(N)

** Space Complexity :- **
A stack is used to store characters — in the worst case (no adjacent pairs cancel), it stores all N characters.
The result string ans is built from the stack and also takes up to N space.

Total Space Complexity :-
Best Case: O(1) → If all characters cancel in pairs immediately.
Worst Case: O(N) → If no characters cancel, both stack and final string occupy space.
Overall: O(N) (Linear Space Complexity)
