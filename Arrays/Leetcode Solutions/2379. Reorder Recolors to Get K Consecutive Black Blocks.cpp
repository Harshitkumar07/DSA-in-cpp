** Leetcode Problem 2379 :- **

You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block.
The characters 'W' and 'B' denote the colors white and black, respectively.
You are also given an integer k, which is the desired number of consecutive black blocks.
In one operation, you can recolor a white block such that it becomes a black block.
Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

Example 1:
Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.

Example 2:
Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.

** Code :- **

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minRecolors = k, currWCount = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') 
                currWCount++;
        }
        minRecolors = currWCount;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W') 
                currWCount--;
            if (blocks[i] == 'W') 
                currWCount++;
            minRecolors = min(minRecolors, currWCount);
        }
        return minRecolors;
    }
};

** Time Complexity :- **

Step 1: Initialize the First Window
The algorithm counts the number of 'W' in the first k blocks.
This takes O(k) time.
Step 2: Sliding Window Traversal
The algorithm slides the window from index k to blocks.size() - 1.
In each step:
It removes the effect of the leftmost element from the count O(1).
It adds the effect of the new rightmost element O(1).
It updates the minimum count in O(1).
Since we iterate through n - k elements, this takes O(n - k) ≈ O(n) time.
Total Time Complexity :
Best Case: O(n) → If the first k elements are already all 'B', no recoloring is needed, but the algorithm still scans the array.
Worst Case: O(n) → The full sliding window approach executes.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **

In-Place Computation :
The function modifies no extra data structures.
It only uses a few integer variables (minRecolors, currWCount, i, k).
Total Space Complexity :
O(1) (Constant Space)
