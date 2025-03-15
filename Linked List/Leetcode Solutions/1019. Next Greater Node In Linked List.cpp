** Leetcode Problem 1019 :- **

You are given the head of a linked list with n nodes.
For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0. 

Example 1:
Input: head = [2,1,5]
Output: [5,5,0]

Example 2:
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]

** Code :- **

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        stack<int> st;
        ListNode* curr = head;
        while (curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }
        vector<int> ans(v.size(), 0);
        for (int i = v.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= v[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(v[i]);
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Converting the Linked List to an Array
The algorithm first traverses the linked list and stores the values in a vector v.
This traversal takes O(N) time, where N is the number of nodes in the linked list.
Step 2: Finding the Next Larger Element Using a Monotonic Stack
The algorithm iterates once through v from right to left.
Each element is pushed onto the stack once and popped at most once.
The total stack operations (push + pop) are O(N).

Total Time Complexity :
Best Case: O(N) → If the list is strictly decreasing, each element is pushed onto the stack only once.
Worst Case: O(N) → If the list is strictly increasing, each element is pushed and popped once.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Vector and Stack
The vector v stores the values from the linked list, requiring O(N) space.
The stack st stores elements in a monotonic decreasing order. In the worst case (strictly increasing sequence), it holds N elements, requiring O(N) space.
The output vector ans stores N elements, requiring O(N) space.

Total Space Complexity :
Best Case: O(N) → If elements are repeated, the stack usage is reduced.
Worst Case: O(N) → If elements are strictly increasing, the stack stores all elements.
Overall: O(N) (Linear Space Complexity)
