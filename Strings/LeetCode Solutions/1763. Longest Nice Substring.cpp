** Leetcode Problem 1763 :- **

A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

Example 1:
Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.

Example 2:
Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.

Example 3:
Input: s = "c"
Output: ""
Explanation: There are no nice substrings.

** Code :- **

class Solution {
public:
    string longestNiceSubstring(string s) {
        int maxLen = 0;
        string longestSubstr;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> set;
            for (int j = i; j < s.size(); j++) {
                set.insert(s[j]);
                bool isNice = true;
                for (char c : set) {
                    if (set.find(toupper(c)) == set.end() ||
                        set.find(tolower(c)) == set.end()) {
                        isNice = false;
                        break;
                    }
                }
                if (isNice && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    longestSubstr = s.substr(i, maxLen);
                }
            }
        }
        return longestSubstr;
    }
};

** Time Complexity :- **
    
Step 1: Brute Force Substring Generation
The algorithm iterates through all substrings using two nested loops:
Outer loop (i) starts at every index: O(n)
Inner loop (j) extends the substring to all possible endings: O(n)
This results in O(n²) substrings being considered.
Step 2: Checking if a Substring is "Nice"
For each substring, an unordered set is used to store characters.
A separate loop iterates over the set to check if every letter has both uppercase and lowercase counterparts.
In the worst case, this takes O(52) ≈ O(1) time since there are at most 26 lowercase and 26 uppercase characters.
Total Time Complexity :
Best Case: O(n²) → If the first substring found is already "nice".
Worst Case: O(n²) → Every substring must be checked for the "nice" condition.
Overall: O(n²) (Quadratic Time Complexity)

** Space Complexity :- **
    
Step 1: Storing Characters in a Hash Set
The unordered set stores distinct characters in a substring.
At most O(52) = O(1) space is used.
Step 2: Storing the Longest Nice Substring
The longestSubstr stores at most O(n) characters, leading to O(n) space usage.
Total Space Complexity :
O(n) (String Storage) + O(1) (Set Storage) = O(n)
