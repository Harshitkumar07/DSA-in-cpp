** Leetcode Problem 867 :- **

Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices. 

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

** Code :- **

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Traversing the Matrix
The algorithm iterates through each element of the original matrix using nested loops.
Outer loop runs m times (number of rows).
Inner loop runs n times (number of columns).
Each element matrix[i][j] is accessed once and assigned to ans[j][i].
Let m be the number of rows and n be the number of columns.

Total Time Complexity :-
Best Case: O(m × n)
Worst Case: O(m × n)
Overall: O(m × n) (Linear with respect to total elements)

** Space Complexity :- **
    
A new matrix ans of size n × m is created to store the transposed values.
It holds the same number of elements as the input matrix.
    
Total Space Complexity :-
Best Case: O(m × n)
Worst Case: O(m × n)
Overall: O(m × n) (Linear Space Complexity)
