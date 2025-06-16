** Leetcode Problem 2390 :- **

You are given a string s, which contains stars *.
In one operation, you can:
Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:
The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

Example 1:
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

Example 2:
Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.

** Code :- **

class Solution {
public:
    string removeStars(string s) {
        string ans;
        for (char c : s) {
            if (c == '*') {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Single Pass Through the String
The algorithm iterates through each character of the input string s.
If the character is not '*', it is appended to the result string ans.
If it is '*', the last character (if any) is removed from ans.
Each character is processed exactly once.
Let N be the length of the string s.
push_back() and pop_back() operations on a string are both O(1) on average.

Total Time Complexity :-
Best Case: O(N) → No stars; all characters are appended.
Worst Case: O(N) → All characters are stars or remove previous ones.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
The algorithm uses a string ans to build the final result.
In the worst case (no stars), ans stores all N characters.
In the best case (all characters cancel out), ans stores very few or no characters.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(N)
Overall: O(N) (Linear Space Complexity)
