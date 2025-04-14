** Leetcode Problem 1047 :- **

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  
The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:
Input: s = "azxxzy"
Output: "ay"

** Code :- **

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == c) {
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
The algorithm traverses the string s from left to right once.

For each character c:
If the stack is not empty and the top of the stack matches c, we pop the stack (O(1)).
Otherwise, we push c onto the stack (O(1)).
Since each character is pushed at most once and popped at most once, the total operations on the stack are linear in the size of the string.

Step 2: Constructing the Result String
After processing, we construct the result string by popping characters from the stack and prepending them to the result string.
Prepending to a string using ans = st.top() + ans takes O(n) in total, as strings are immutable and each prepend may take O(n) time.
To optimize this step, we can build the string in reverse order and reverse it once at the end using a stringstream or a vector<char>.

Total Time Complexity :- 

Best Case: O(n) → No adjacent duplicates.
Worst Case: O(n²) due to repeated string prepending.
Optimized Case: O(n) if we use efficient string building (e.g., vector<char> + reverse).

** Space Complexity :- **
    
Step 1: Stack Usage
In the worst case (e.g., when no adjacent duplicates exist), every character is stored in the stack.
Hence, space used by the stack is O(n).

Step 2: Output String
The output string also stores up to n characters in the worst case, giving another O(n).

Total Space Complexity :-
Best Case: O(1) → If all characters are canceled by adjacent duplicates.
Worst Case: O(n) → Stack and result string hold all characters.
Overall: O(n)
