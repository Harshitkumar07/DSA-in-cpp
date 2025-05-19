** Leetcode Problem 2900 :- **

You are given a string array words and a binary array groups both of length n.
A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements at the same indices in groups are different (that is, there cannot be consecutive 0 or 1).
Your task is to select the longest alternating subsequence from words.
Return the selected subsequence. If there are multiple answers, return any of them.
Note: The elements in words are distinct.

Example 1:
Input: words = ["e","a","b"], groups = [0,0,1]
Output: ["e","b"]
Explanation: A subsequence that can be selected is ["e","b"] because groups[0] != groups[2]. Another subsequence that can be selected is ["a","b"] because groups[1] != groups[2].
It can be demonstrated that the length of the longest subsequence of indices that satisfies the condition is 2.

Example 2:
Input: words = ["a","b","c","d"], groups = [1,0,1,1]
Output: ["a","b","c"]
Explanation: A subsequence that can be selected is ["a","b","c"] because groups[0] != groups[1] and groups[1] != groups[2]. Another subsequence that can be selected is ["a","b","d"] because groups[0] != groups[1] and groups[1] != groups[3]. 
It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.

** Code :- **

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        for (int i = 0; i < groups.size(); i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};

** Time Complexity :- **
Step 1: Iterating Through the Groups Array
The algorithm iterates through the groups vector from i = 0 to i < groups.size():
For each index i, it checks whether it is the first element (i == 0) or whether groups[i] differs from the previous group (groups[i] != groups[i - 1]).
If the condition is true, it pushes words[i] into the result vector.
Each of these operations (comparison, access, and push) is constant time: O(1).

Total Time Complexity :-
Best Case: O(N) → Every element is processed once.
Worst Case: O(N) → Entire groups vector is traversed.
Overall: O(N), where N is the size of the groups (and words) vector.

** Space Complexity :- **
    
Step 1: Result Vector ans
In the worst case, every group is different from the previous, so every words[i] is pushed into the ans vector.
Thus, ans can grow to contain up to N elements.
No other auxiliary data structures are used beyond this.

Total Space Complexity :-
Best Case: O(1) → If only one word is selected, minimal extra space is used.
Worst Case: O(N) → If all words belong to different groups.
Overall: O(N) (Linear Space Complexity in the Worst Case)
