** Leetcode Problem 94 :- **

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

** Code :- **

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Inorder Traversal (Recursive Function)
The inorder function visits each node exactly once.

For each node:
It recursively visits the left subtree.
Processes the current node (adds to result vector).
Recursively visits the right subtree.

If there are N nodes in the tree:
The total number of recursive calls is N.
Each call does constant work.

Total Time Complexity :-
Best Case: O(N) → All nodes are visited once.
Worst Case: O(N) → Applies to skewed or balanced trees.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Output Storage
The result is stored in a vector ans of size N.
Space used: O(N)

Step 2: Recursive Call Stack
The call stack depth depends on the height of the tree:
Best Case (balanced tree): Height = O(log N)
Worst Case (completely skewed tree): Height = O(N)

Total Space Complexity :-
Best Case: O(N) (vector) + O(log N) (stack) = O(N)
Worst Case: O(N) (vector) + O(N) (stack) = O(N)
Overall: O(N) (Linear Space Complexity in the worst case)
