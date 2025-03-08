** Leetcode Problem 48 :- **

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation. 

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

** Code :- **

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

** Time Complexity :- **
    
Step 1: Transposing the Matrix
The first loop swaps matrix[i][j] with matrix[j][i] for i < j, ensuring only upper triangular elements are swapped.
Since we iterate over approximately half of the elements, this step takes O(n² / 2) = O(n²) time.
Step 2: Reversing Each Row
The second loop reverses each row of the matrix.
Since reversing an array of length n takes O(n) time and there are n rows, this step takes O(n²) time.
Total Time Complexity :
Best Case: O(n²) → The matrix is already rotated, but both steps still execute.
Worst Case: O(n²) → The matrix is fully rotated.
Overall: O(n²) (Quadratic Time Complexity)

** Space Complexity :- **
    
In-Place Computation :
The function modifies the matrix in place without using extra storage.
Only a few integer variables (i, j, n) are used.
Total Space Complexity :
O(1) (Constant Space)
