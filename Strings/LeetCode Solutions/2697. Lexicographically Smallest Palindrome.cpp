** Leetcode Problem 2697 :- **

You are given a string s consisting of lowercase English letters, and you are allowed to perform operations on it. In one operation, you can replace a character in s with another lowercase English letter.
Your task is to make s a palindrome with the minimum number of operations possible. If there are multiple palindromes that can be made using the minimum number of operations, make the lexicographically smallest one.
A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
Return the resulting palindrome string.

Example 1:
Input: s = "egcfe"
Output: "efcfe"
Explanation: The minimum number of operations to make "egcfe" a palindrome is 1, and the lexicographically smallest palindrome string we can get by modifying one character is "efcfe", by changing 'g'.

Example 2:
Input: s = "abcd"
Output: "abba"
Explanation: The minimum number of operations to make "abcd" a palindrome is 2, and the lexicographically smallest palindrome string we can get by modifying two characters is "abba".

Example 3:
Input: s = "seven"
Output: "neven"
Explanation: The minimum number of operations to make "seven" a palindrome is 1, and the lexicographically smallest palindrome string we can get by modifying one character is "neven".

** Code :- **

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                char minChar = min(s[left], s[right]);
                s[left] = s[right] = minChar;
            }
            left++;
            right--;
        }
        return s;
    }
};

** Time Complexity :- **
    
Step 1: Two-Pointer Traversal
The function uses a two-pointer approach (left and right) starting from both ends of the string.

In each iteration:
It compares s[left] and s[right].
If they differ, both are updated to the lexicographically smaller character.
The loop runs while left < right, which means approximately N / 2 iterations for a string of length N.

Total Time Complexity :-
Best Case: O(N) → Even if no characters are changed, the entire string is still traversed once.
Worst Case: O(N) → Every pair of characters needs to be compared and possibly modified.
Overall: O(N), where N is the length of the string s.

** Space Complexity :- **
Step 1: In-Place Modification
The string s is modified in-place (no additional data structures are used).
Only a constant number of extra variables (left, right, minChar) are used.

Total Space Complexity :-
Best Case: O(1) → No extra space used beyond a few variables.
Worst Case: O(1) → Still constant space regardless of input size.
Overall: O(1) (Constant Space Complexity)
