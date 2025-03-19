** Leetcode Problem 84 :- **

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram. 

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

** Code :- **

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)
            return 0;
        vector<int> left(n, 0);  // nearest left samller
        vector<int> right(n, 0); // nearest right smaller
        stack<int> st;
        
        // Right smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        // Left smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Finding the Nearest Smaller Element to the Right
The algorithm iterates through heights once from right to left.
Each element is pushed onto the stack once and popped at most once.
The total number of operations for this step is O(N).
Step 2: Finding the Nearest Smaller Element to the Left
The algorithm iterates through heights once from left to right.
Each element is pushed onto the stack once and popped at most once.
The total number of operations for this step is O(N).
Step 3: Computing Maximum Area
The algorithm iterates once through heights to compute the maximum area.
This takes O(N) time.

Total Time Complexity :
Best Case: O(N) → If heights is already sorted, each element is processed once.
Worst Case: O(N) → Even if all elements are equal, each element is pushed and popped once.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Stack
The stack stores indices of histogram bars in a monotonic increasing order.
In the worst case (strictly increasing sequence), it holds N elements, requiring O(N) space.
Step 2: Storage for left and right Arrays
The left and right arrays store the nearest smaller elements' indices.
Each array requires O(N) space.

Total Space Complexity :
Best Case: O(N) → If elements are repeated, stack usage is reduced.
Worst Case: O(N) → If all elements are unique, the stack stores all elements.
Overall: O(N) (Linear Space Complexity)
