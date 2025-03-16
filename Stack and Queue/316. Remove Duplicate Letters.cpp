** Leetcode Problem 316 :- **

Given a string s, remove duplicate letters so that every letter appears once and only once.
You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

** Code :- **

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, bool> isvisited;
        unordered_map<char, int> lastOccurance;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            lastOccurance[s[i]] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            if (!isvisited[s[i]]) {
                while (!st.empty() &&
                       (st.top() > s[i] && lastOccurance[st.top()] > i)) {
                    isvisited[st.top()] = false;
                    st.pop();
                }
                st.push(s[i]);
                isvisited[s[i]] = true;
            }
        }
        string result ;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};

** Time Complexity :- **

Calculating Last Occurrence:
The lastOccurance map is built in a single pass through the string s, which takes O(n), where n is the length of the string.
Processing Each Character:
The main loop iterates through each character of the string s, which takes O(n).
For each character, in the worst case, we might pop elements from the stack. 
Since each character is pushed and popped from the stack at most once, the operations on the stack cumulatively take O(n).
Building the Result:
Once the stack is built, reconstructing the final result string from the stack involves popping all elements, which takes O(n).
Total Time Complexity:
Each step operates in O(n), and all operations combined sum up to: O(n)

** Space Complexity :- **

Hash Maps (isvisited and lastOccurance):
Both maps store a single entry for each distinct character in the string. Since there are at most 26 lowercase English letters, the space required is O(1) (constant space).
Stack (st):
The stack can store at most 26 unique characters, leading to O(1) space.
Result String (result):
The final result string contains at most 26 characters, contributing O(1) space.
Auxiliary Variables:
A constant amount of extra space is used for variables like indices and temporary characters.
Total Space Complexity:
While multiple structures are used, each is capped at 26 entries, leading to: O(1)
