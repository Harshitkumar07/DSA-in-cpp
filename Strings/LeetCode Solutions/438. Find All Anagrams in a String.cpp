** Leetcode Problem 438 :- **

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

** Code :- **

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int sLen = s.length(), pLen = p.length();
        if (sLen < pLen)
            return ans;
        vector<int> pCount(26, 0);
        for (char c : p) {
            pCount[c - 'a']++;
        }
        vector<int> sCount(26, 0);
        for (int i = 0; i < pLen; i++) {
            sCount[s[i] - 'a']++;
        }
        if (sCount == pCount) {
            ans.push_back(0);
        }
        for (int i = pLen; i < sLen; i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - pLen] - 'a']--;
            if (sCount == pCount) {
                ans.push_back(i - pLen + 1);
            }
        }

        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Counting Frequency of p
The algorithm creates a frequency count for p, iterating through its characters.
This takes O(pLen) = O(m) time, where m is the length of p.
Step 2: Counting Frequency of the First Window in s
The frequency count for the first pLen characters in s is created.
This takes O(pLen) = O(m) time.
Step 3: Sliding Window Comparison
The algorithm slides a window of length pLen across s, updating the frequency array in O(1) time per step.
Since there are O(n - m) windows (where n is the length of s), this takes O(n - m) ≈ O(n) time.
Total Time Complexity :
Best Case: O(n) → If s is much longer than p, the algorithm efficiently scans s once.
Worst Case: O(n) → Every window is checked, but each comparison is constant time.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storing Frequency Arrays
Two fixed-size frequency arrays of size 26 (pCount and sCount) are used.
This requires O(26) = O(1) space.
Step 2: Output List (ans)
The result vector stores the indices of valid anagrams.
In the worst case, all n - m + 1 indices are stored, leading to O(n) space.
Total Space Complexity :
O(1) (Frequency Arrays) + O(n) (Output Storage) = O(n)
