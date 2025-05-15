** Leetcode Problem 3206 :- ** 

There is a circle of red and blue tiles. You are given an array of integers colors. The color of tile i is represented by colors[i]:
colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
Every 3 contiguous tiles in the circle with alternating colors (the middle tile has a different color from its left and right tiles) is called an alternating group.
Return the number of alternating groups.
Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

Example 1:
Input: colors = [1,1,1]
Output: 0

Example 2:
Input: colors = [0,1,0,0,1]
Output: 3

** Code :- **

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size(), count = 0;
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[(i + 1) % n] &&
                colors[(i + 1) % n] != colors[(i + 2) % n]) {
                count++;
            }
        }
        return count;
    }
};

** Time Complexity :- **
    
    
Step 1: Iterating Through the Array
The function loops through the colors vector using a single for loop that runs n times, where n is the size of the vector.

Step 2: Checking Alternation Condition
For each index i, the function checks:
colors[i] != colors[(i + 1) % n] and
colors[(i + 1) % n] != colors[(i + 2) % n]
These are constant-time comparisons.
Therefore, each iteration does O(1) work.

Total Time Complexity :-
O(n), where n is the size of the input vector.

** Space Complexity :- **
    
Step 1: Variable Usage
Only a few integer variables are used (n, count, and loop variable i).
No additional data structures are used that grow with input size.

Total Space Complexity :-
O(1) (constant space)
