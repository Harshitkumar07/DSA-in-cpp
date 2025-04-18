** Leectcode Problem 1941 :- **

Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:
Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.

** Code :- **

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> map;
        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            map[s[i]] += 1;
            ans = max(map[s[i]], ans);
        }
        for (auto c : map) {
            if (c.second != ans) {
                return false;
            }
        }
        return true;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the String :
The algorithm iterates through the string s character by character.
For each character, it increments its count in the unordered_map, which takes O(1) time for each insertion or update.
This step takes O(n) time, where n is the length of the string s.

Step 2: Iterating Through the Map
After constructing the frequency map, the algorithm iterates over the map (which contains at most m unique characters).
In the worst case, the map has a size of O(26) (if all characters in the string are distinct English lowercase letters).
Checking the frequency for each character takes O(1), so this step runs in O(m) time, where m is the number of unique characters.

Total Time Complexity :-
    
The total time complexity is the sum of the two steps:

Step 1: O(n) (iterating over the string).
Step 2: O(m) (iterating over the map).
Since m is at most 26 (for lowercase English letters), we can consider this constant, making the total time complexity:

Best Case: O(n) – In case all characters are the same.
Worst Case: O(n) – If there are distinct characters, but the size of the map is still constant.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Space for the Frequency Map
The algorithm uses an unordered_map to store the frequencies of characters.
The space used by this map is proportional to the number of unique characters in the string s. In the worst case, this can be O(26), which is a constant space.

Step 2: Constant Space for Other Variables
The algorithm uses a few integer variables like ans, but they don't depend on the size of the input.

Total Space Complexity :-
Overall: O(1) – Constant space complexity (since the number of unique lowercase English letters is fixed at 26).
