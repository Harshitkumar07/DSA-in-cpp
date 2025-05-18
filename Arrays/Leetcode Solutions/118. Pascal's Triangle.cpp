** Leetcode Problem 118 :- **

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

** Code :- **

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through Rows
The algorithm runs a loop from i = 0 to i < numRows, creating each row.
Total iterations: numRows times.

Step 2: Filling Each Row
For each row i, a loop runs from j = 1 to j < i to compute intermediate values:
ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
This inner loop executes i - 1 times for row i.
Total operations across all rows:
Which is O(numRows²) in the worst case.

Total Time Complexity :-
Best Case: O(numRows²) → Still needs to build all rows even if unused later.
Worst Case: O(numRows²) → All elements are computed.
Overall: O(numRows²)

** Space Complexity :- **

Step 1: Storing the Triangle
A 2D vector ans is used to store all rows of the triangle.
Each row i contains i + 1 elements.
Total number of elements stored:
This evaluates to O(numRows²).

Total Space Complexity :-
Best Case: O(numRows²) → All rows are stored in memory.
Worst Case: O(numRows²) → Space grows quadratically with numRows.
Overall: O(numRows²)
