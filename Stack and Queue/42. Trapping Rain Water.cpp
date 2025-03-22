** Leetcode Problem 42 :- **

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining. 

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

** Code :- **

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int width = i - st.top() - 1;
                int minHeight = min(height[i], height[st.top()]) - height[top];
                ans += width * minHeight;
            }
            st.push(i);
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the Heights Array
The algorithm iterates once through the height array from left to right.
Each element is pushed onto the stack once and popped at most once.
Since each element is processed at most twice (push and pop), the total operations are O(N).

Total Time Complexity :
Best Case: O(N) → If heights are strictly increasing or decreasing, elements are pushed once and never popped.
Worst Case: O(N) → Each element is pushed and popped once.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Stack
The stack stores indices of histogram bars in a monotonic decreasing order.
In the worst case (strictly increasing sequence), the stack holds N elements, requiring O(N) space.

Total Space Complexity :
Best Case: O(1) → If the height array is empty or has no trapped water, stack usage is minimal.
Worst Case: O(N) → If heights are strictly increasing, the stack stores all elements.
Overall: O(N) (Linear Space Complexity in the Worst Case)
