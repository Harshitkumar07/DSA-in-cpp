** Leetcode Problem 3174 :- **

You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:
Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

Example 1:

Input: s = "abc"
Output: "abc"
Explanation:
There is no digit in the string.

Example 2:
    
Input: s = "cb34"
Output: ""
Explanation:
First, we apply the operation on s[2], and s becomes "c4".
Then we apply the operation on s[1], and s becomes "".

** Code :- **

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char ch : s) {
            if (isdigit(ch)) {
                if (!st.empty() && !isdigit(st.top())) {
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

** Time Complexity :- **

Iterating Over String (for (char ch : s)) 
The loop runs O(n) times, where n is the length of the string.
Each character is processed once.
Stack Operations (st.push(ch), st.pop())
Each character is either pushed or popped once, contributing O(1) per operation.
Since we process each character at most once, the total contribution remains O(n).
Constructing the Output String (while (!st.empty()))
This loop runs O(n) times in the worst case (when all characters are stored in the stack).
Reversing the string (reverse(ans.begin(), ans.end())) takes O(n).
Total Time Complexity :
Best Case: O(n) → If no digits exist, only a single pass is needed.
Worst Case: O(n) → If all characters go into the stack and need to be reversed.
Since all operations are linear, the overall time complexity is O(n).

** Space Complexity :- **
    
Stack (stack<char> st)    
In the worst case, all characters (excluding digits) are stored in the stack.
This results in O(n) space usage.
Output String (string ans) :
The final output string may also store up to O(n) characters.
Total Space Complexity :
Best Case: O(1) → If the string contains only digits, no extra space is used.
Worst Case: O(n) → When all non-digit characters are stored in both the stack and result string.
The overall space complexity is O(n).
