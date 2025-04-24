** Leetcode Problem 108 :- **

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

** Code :- **

class Solution {
public:
    TreeNode* solve(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = solve(nums, start, mid - 1);
        temp->right = solve(nums, mid + 1, end);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n - 1);
    }
};

** Time Complexity :- **
    
Step 1: Recursive Tree Construction
At each recursive call, the array is divided into two halves:
The middle element becomes the current root.
Left subarray goes to the left subtree.
Right subarray goes to the right subtree.
Each element in the array is visited exactly once to create a node.

Number of Recursive Calls:
The recursion behaves like a binary search.
For n elements, we make n recursive calls — one per node.

Overall Time Complexity: O(n)
Every element is visited once, and tree node creation is constant time per node.

** Space Complexity :- **
    
Step 1: Recursion Stack
The space used by the recursion stack depends on the height of the tree.
For a balanced tree (ideal scenario), height is O(log n).
In the worst case (if the input array somehow causes unbalanced splitting — although not with this midpoint logic), height could be O(n) — but not for this implementation.

Step 2: No Extra Space for Tree Storage
Nodes are created dynamically, but this is part of the output, not auxiliary space.

Overall Space Complexity :-
O(log n) for recursion stack in the best case (balanced tree).
O(n) in the worst case (deep recursion — not applicable here due to midpoint splitting).
