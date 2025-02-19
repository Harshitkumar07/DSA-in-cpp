** Leetcode Problem 1079 :- **

You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

Example 1:
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
Input: tiles = "AAABBC"
Output: 188

Example 3:
Input: tiles = "V"
Output: 1

** Code :- **

class Solution {
public:
    void backtrack(string& tiles, int start, int& ans, vector<bool>& used) {
        if (start > 0) 
            ans++;
        for (int i = 0; i < tiles.size(); ++i) {
            if (used[i])
                continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            backtrack(tiles, start + 1, ans, used);
            used[i] = false;
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        int ans = 0;
        vector<bool> used(tiles.size(), false);
        backtrack(tiles, 0, ans, used);
        return ans;
    }
};

** Time Complexity :- **
    
Sorting Step (sort(tiles.begin(), tiles.end())) :
Sorting the string takes O(n log n) time, where n is the length of tiles.
Backtracking Function (backtrack) :
The function explores all possible subsets of the tiles string using backtracking.
Each character can either be included or not, leading to O(2ⁿ) worst-case complexity.
However, due to duplicate character skipping and pruning, the complexity reduces closer to O(n!) in the worst case.
Overall Time Complexity :
The overall complexity is O(n log n) + O(n!) ≈ O(n!), as factorial growth dominates the logarithmic sorting.

** Space Complexity :- **
    
Auxiliary Storage (vector<bool> used) :
Uses an array of size n (used), requiring O(n) space.
Recursive Stack Space :
In the worst case, the recursion depth is O(n) (each character is used in a sequence).
Total Space Complexity :
The total space complexity is O(n) + O(n) = O(n).
