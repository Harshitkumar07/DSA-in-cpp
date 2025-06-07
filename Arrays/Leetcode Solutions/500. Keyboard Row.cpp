** Leetcode Problem 500 :- **

Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the American keyboard:
the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Explanation:
Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

Example 2:
Input: words = ["omk"]
Output: []

Example 3:
Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]

** Code :- **

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> set1{'q', 'w', 'e', 'r', 't','y', 'u', 'i', 'o', 'p'};
        unordered_set<char> set2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> set3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        vector<string> ans;
        unordered_set<char> set;
        for (string word : words) {
            if (set1.find(tolower(word[0])) != set1.end()) {
                set = set1;
            } else if (set2.find(tolower(word[0])) != set2.end()) {
                set = set2;
            } else {
                set = set3;
            }
            bool count = 1;
            for (char l : word) {
                if (set.find(tolower(l)) == set.end()) {
                    count = 0;
                    break;
                }
            }
            if (count) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Let n be the number of words and L be the average length of each word.

Step 1: Initializing Sets
The sets set1, set2, and set3 are initialized with constant number of characters → O(1)

Step 2: Loop Over Words
You iterate through each word → O(n)

Step 3: Character Checks for Each Word
For each character in the word (up to L), you:

Convert it to lowercase → O(1)
Check membership in a set → O(1) (since unordered_set has average-case constant time lookup)
So, for n words of average length L: O(n⋅L)

Total Time Complexity :-
    
Best Case: O(n × L)
Worst Case: O(n × L)
Overall: O(n × L)

** Space Complexity :- **
    
Sets:
You use three unordered_set<char> with fixed keyboard rows (10, 9, 7 characters) → O(1)

Output Vector:
In the worst case, all n words could be valid → output vector holds n strings

Temporary Set & Word Copies:
One temporary set (set) and strings copied from input (each of length up to L)

Total Space Complexity :-
Best Case: O(1) → If no words are valid
Worst Case: O(n × L) → If all words are valid and stored
Overall: O(n × L)
