** Leetcode Problem 3442 :- **

You are given a string s consisting of lowercase English letters.
Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.

Example 1:
Input: s = "aaaaabbc"
Output: 3
Explanation:
The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
The maximum difference is 5 - 2 = 3.

Example 2:
Input: s = "abcabcab"
Output: 1
Explanation:
The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
The maximum difference is 3 - 2 = 1.

** Code :- **

class Solution {
public:
    int maxDifference(string s) {
        int odd = INT_MIN, even = INT_MAX;
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int n : freq) {
            if (n == 0) {
                continue;
            }
            if (n % 2 == 0) {
                even = min(even, n);
            } else {
                odd = max(odd, n);
            }
        }
        return odd - even;
    }
};

** Time Complexity :- **
    
Step 1: Counting Frequencies
The algorithm initializes an array freq of size 26 to store the frequency of each lowercase English letter.
It iterates over the string s once and increments the corresponding index in freq for each character.
Let N be the length of the string s.
This step takes O(N) time.

Step 2: Processing the Frequency Array
It then iterates over the fixed-size freq array (size 26).
For each non-zero frequency:
If the frequency is even, it updates the minimum even.
If the frequency is odd, it updates the maximum odd.
This step takes constant time: O(26) → O(1)

Total Time Complexity :-
Best Case: O(N)
Worst Case: O(N)
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
The algorithm uses:
An integer array of fixed size 26 to store frequencies.
A few integer variables: odd, even, and loop counters.
No dynamic or input-size-dependent space is used beyond that.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Space Complexity)
