** Leetcode Problem 240 :- **

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom. 

Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

** Code :- **

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0) {
            int curr = matrix[row][col];
            if (curr == target) {
                return true;
            } else if (curr > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};

** Time Complexity :- **
    
Step 1: Searching the Matrix (while loop)
The algorithm starts from the top-right corner and moves left if the current element is greater than target or down if it is smaller.
Each step either moves left (col--) or moves down (row++), reducing either the number of columns or rows.
Since the matrix has m rows and n columns, the worst case is O(m + n).
Total Time Complexity :
Best Case: O(1) → If target is found at the starting position (top-right corner).
Worst Case: O(m + n) → If the target is not in the matrix, we traverse the full height/width.
Overall: O(m + n) (Linear Complexity in Matrix Dimensions)

** Space Complexity :- **
    
Step 1: In-Place Searching
The function modifies no extra data structures.
It only uses a few integer variables (rows, cols, row, col, curr).
Total Space Complexity :
O(1) (Constant Space Complexity)
