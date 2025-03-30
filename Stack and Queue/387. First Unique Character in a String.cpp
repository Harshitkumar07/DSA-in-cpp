** Leetcode Problem 387 :- **

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0
Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

** Code :- **

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        queue<int> q;
        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) == map.end()) {
                q.push(i);
            }
            map[s[i]]++;
            while (q.size() > 0 && map[s[q.front()]] > 1) {
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};

** Time Complexity :- **
    
Step 1: Constructing Character Frequency Map
The algorithm iterates through the string s once and updates the frequency count in an unordered map.
Each operation (map[s[i]]++) takes O(1) on average.
Total Complexity: O(N)

Step 2: Identifying the First Unique Character
The algorithm iterates through the string again to find the first character with a frequency of 1.
This loop also takes O(N).

Total Time Complexity :-
Best Case: O(N) → If the first character is unique, the second loop exits early.
Worst Case: O(N) → If the unique character is at the end, the second loop iterates fully.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Character Frequency Map
The unordered map can store at most 26 keys (since the string consists of lowercase English letters).
Space: O(1) (constant space, independent of N).

Step 2: Storage for Queue (Original Implementation)
The queue stores at most N indices in the worst case.
Space: O(N) (Linear Space Complexity).
Optimized Approach (Using an Array Instead of a Queue)
If we replace the unordered map with a fixed-size array of 26 elements, we reduce space usage.
Space: O(1) (constant space).

Total Space Complexity :-
Best Case: O(1) → If we use a fixed-size frequency array.
Worst Case: O(N) → If we use a queue to track character indices.
Overall: O(1) (Optimized) or O(N) (Queue-Based Approach).
