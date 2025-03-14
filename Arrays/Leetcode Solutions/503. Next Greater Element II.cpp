** Leetcode Problem 503 :- **

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

** Code :- **

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[idx] = st.top();
            }
            st.push(nums[idx]);
        }
        
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the Circular Array
The algorithm iterates 2N times because it considers the circular nature of the array.
Each element is pushed onto the stack once and popped at most once.
Since each element is pushed and popped at most once, the total stack operations are O(N).
Total Time Complexity :
Best Case: O(N) → If the array is strictly decreasing, each element is pushed once and popped once.
Worst Case: O(N) → If the array is strictly increasing, each element is pushed once and popped once.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Stack and Result Array
The stack stores elements from nums. In the worst case (strictly increasing sequence), it holds N elements, requiring O(N) space.
The output vector ans stores N elements, requiring O(N) space.

Total Space Complexity :
Best Case: O(N) → If all elements are the same, the stack usage is reduced.
Worst Case: O(N) → If nums is strictly increasing, the stack stores all elements.
Overall: O(N) (Linear Space Complexity)
