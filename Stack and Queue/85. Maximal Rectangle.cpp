** Leetcode Problem 85 :- **

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area. 

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1

** Code :- **

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        // nearest right maximum
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }
        // clear before use
        while (!st.empty()) {
            st.pop();
        }
        // nearest left minimum
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = height[i] * width;
            result = max(result, currArea);
        }
        return result;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> height(col, 0);
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    height[j]++;
                }
            }
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Computing the Largest Rectangle in a Histogram
The largestRectangleArea function processes N elements using a monotonic stack:
Each element is pushed and popped at most once, leading to O(N) operations.
This is repeated for each row in the matrix.

Step 2: Constructing Heights from the Matrix
The maximalRectangle function iterates through each row and updates the height array in O(M) time, where M is the number of columns.
The function then calls largestRectangleArea for each row, making the total time complexity O(M) + O(N) = O(N + M) per row.

Total Time Complexity :-
Best Case: O(NM) → If the matrix is small or has many zeros, reducing histogram complexity.
Worst Case: O(NM) → Each row processes a histogram in O(M) time.
Overall: O(NM) (Quadratic Time Complexity for Matrix Processing)

** Space Complexity :- **

Step 1: Storage for Stack and Arrays
The largestRectangleArea function uses:
Two O(N) arrays (left, right) for nearest smaller elements.
A stack of size O(N).
The maximalRectangle function uses:
A height array of size O(M) to maintain column heights.

Total Space Complexity :
Best Case: O(M) → If the matrix has only one row, minimal space is used.
Worst Case: O(M + N) → The stack and arrays store M or N elements.
Overall: O(M + N) (Linear Space Complexity in Terms of Rows and Columns)
