** Leetcode Problem 73 :- ** 

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place. 

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

** Code :- **

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < m; k++) {
                        visited[i][k] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        visited[k][j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = visited[i][j];
            }
        }
    }
};

** Time Complexity :- **
    
Step 1: Copying the Matrix (visited = matrix)
Copying an n × m matrix takes O(n × m) time.
Step 2: Marking Rows with Zero
The first nested loop iterates over all elements of the matrix (O(n × m)).
If a 0 is found at (i, j), the entire row i is set to 0 in visited, taking O(m) time.
In the worst case, where all elements are 0, this results in O(n × m) + O(n × m) = O(n × m).
Step 3: Marking Columns with Zero
The second nested loop also iterates over all elements (O(n × m)).
If a 0 is found, the entire column j is set to 0 in visited, taking O(n) time.
In the worst case, this results in O(n × m) + O(n × m) = O(n × m).
Step 4: Copying visited Back to matrix
Copying an n × m matrix takes O(n × m) time.
Total Time Complexity :
Best Case: O(n × m) → If no zeros are present, all loops still execute.
Worst Case: O(n × m) → All loops process each element at most twice.
Overall: O(n × m) (Quadratic Time Complexity)

** Space Complexity :- **
    
Step 1: Extra visited Matrix (O(n × m))
The function creates an additional n × m matrix visited, requiring O(n × m) space.
Step 2: Auxiliary Variables (O(1))
The function only uses a few integer variables (i, j, k, n, m).
Total Space Complexity :
O(n × m) (Extra Matrix Storage)
