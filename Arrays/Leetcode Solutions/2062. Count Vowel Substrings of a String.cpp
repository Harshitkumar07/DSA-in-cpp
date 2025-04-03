** Leetcode Problem 2062 :- **

A substring is a contiguous (non-empty) sequence of characters within a string.
A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
Given a string word, return the number of vowel substrings in word.

Example 1:
Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"

Example 2:
Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.

Example 3:
Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"

** Code :- **

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int countVowelSubstrings(string word) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            unordered_set<char> set;
            for (int j = i; j < word.size(); j++) {
                if (!isVowel(word[j]))
                    break;
                set.insert(word[j]);
                if (set.size() == 5)
                    ans++;
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Over Start Indices
The outer loop runs from i = 0 to i < word.size(), iterating over all starting indices.
This results in O(N) iterations, where N is the length of word.

Step 2: Expanding to Find Vowel Substrings
For each starting index i, the inner loop expands to the right until:
A non-vowel character is encountered (causing an early exit).
All 5 vowels (a, e, i, o, u) have been encountered.
In the worst case, the inner loop could extend to the end of the string, leading to O(N) operations per starting index.

Step 3: Using an Unordered Set
The unordered set ensures that we efficiently track unique vowels.
Insertions and lookups in an unordered set have O(1) average time complexity.
The set can hold at most 5 vowels, making its size constant.

Total Time Complexity :-
Best Case: O(N) → If there are very few vowels, the inner loop exits early.
Worst Case: O(N²) → If all characters are vowels, the inner loop runs fully for each i.
Overall: O(N²) (Quadratic Time Complexity in the Worst Case).

** Space Complexity :- **
    
Step 1: Storage for Unordered Set
The unordered set stores at most 5 elements (the vowels), making it O(1) space.
Step 2: No Extra Data Structures
The algorithm only uses integer variables (ans, i, j), which are constant in space.

Total Space Complexity :-
Best Case: O(1) → Only a few vowels need to be stored.
Worst Case: O(1) → At most 5 vowels are stored in the unordered set.
Overall: O(1) (Constant Space Complexity).
