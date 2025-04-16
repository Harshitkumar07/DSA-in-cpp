** Leetcode Problem 2124 :- **

Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

Example 1:
Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.

Example 2:
Input: s = "abab"
Output: false
Explanation:
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.

Example 3:
Input: s = "bbb"
Output: true
Explanation:
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.

** Code :- **

class Solution {
public:
    bool checkString(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == 'a' && s[i - 1] == 'b') {
                return false;
            }
        }
        return true;
    }
};

** Time Complexity :- **
    
    
Step 1: Iterating Through the String
The function iterates through the string s starting from index 1 to the end.

For each character, it checks if:
The current character is 'a' and
The previous character is 'b'
This is done in a single loop running from index 1 to s.size() - 1, so each character is checked exactly once.

Total Time Complexity :-
Best Case: O(1) – If a 'ba' pattern is found early (e.g., "ba"), the function exits immediately.
Worst Case: O(n) – If the string is valid or the invalid pattern occurs at the end.
Overall: O(n) where n is the length of the string.

** Space Complexity :- **
    
Step 1: Auxiliary Space
No extra data structures are used apart from a few integer variables for iteration.
All operations are done in-place using constant space.

Total Space Complexity :-
Overall: O(1) – Constant space usage regardless of the input size.
