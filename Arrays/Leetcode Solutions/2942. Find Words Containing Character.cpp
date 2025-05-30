** Leetcode Problem 2942 :- **

You are given a 0-indexed array of strings words and a character x.
Return an array of indices representing the words that contain the character x.
Note that the returned array may be in any order.

Example 1:
Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.

Example 2:
Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
Output: [0,2]
Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.

Example 3:
Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
Output: []
Explanation: "z" does not occur in any of the words. Hence, we return an empty array.

** Code :- **

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                if (c == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Outer Loop Over Words
The loop runs n times, where n = words.size().

Step 2: Inner Loop Over Characters
For each word, we may iterate through up to L characters (length of the word) to search for the character x.
In the worst case, we scan all characters in each word.
If L is the average length of the words, the total operations : O(n⋅L)

Total Time Complexity :- 
Best Case: O(n) → If x is the first character in each word.
Worst Case: O(n × L)
Overall: O(n × L)

** Space Complexity :- **
    
ans stores the indices of words that contain x.
In the worst case, every word might contain x, so ans would store all n indices.

Total Space Complexity :- 
Best Case: O(1) → If no word contains x.
Worst Case: O(n)
Overall: O(n)
