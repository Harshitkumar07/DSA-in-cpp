** Leetcode Problem 145 :- **

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,6,7,5,2,9,8,3,1]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

** Code :- **

class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Postorder Traversal (Recursive Function)
The postorder function visits each node exactly once.

For each node:
It recursively visits the left subtree.
Then the right subtree.
    
Finally, processes the current node by adding its value to the result vector.
If there are N nodes in the binary tree:
There are N recursive calls, one per node.
Each call does constant work (one insertion and a few comparisons).

Total Time Complexity :- 
Best Case: O(N) → Each node is visited once.
Worst Case: O(N) → Applies to any tree structure.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Output Storage
The vector ans stores the result and grows to a size of N.

Step 2: Recursive Call Stack
The maximum depth of the recursion depends on the height of the tree:
Best Case (balanced tree): O(log N)
Worst Case (skewed tree): O(N)

Total Space Complexity :-
Best Case: O(N) (vector) + O(log N) (stack) = O(N)
Worst Case: O(N) (vector) + O(N) (stack) = O(N)
Overall: O(N) (Linear Space Complexity in the worst case)
