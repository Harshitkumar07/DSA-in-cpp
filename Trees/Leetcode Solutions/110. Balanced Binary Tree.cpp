** Leetcode Problem 110 :- **

Given a binary tree, determine if it is height-balanced. 

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

** Code :- **

class Solution {
public:
    int check(TreeNode* root) {
        if (!root)
            return 0;
        int left = check(root->left), right = check(root->right);

        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) { 
        return check(root) != -1; 
    }
};

** Time Complexity :- **
    
Step 1: Postorder Traversal with Height Check
The algorithm uses a postorder traversal (left → right → node).

For each node:
It computes the height of the left and right subtree.
It compares their difference.
It returns -1 early if any subtree is unbalanced.
Each node is visited once, and each visit does constant work (comparison and max calculation).
If the tree has N nodes, every node is checked once.

Total Time Complexity :-
Best Case: O(N) → Even if unbalanced early, the algorithm may still need to traverse most nodes.
Worst Case: O(N) → Full traversal is required for balanced trees.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Recursive Call Stack
The height of the recursion stack depends on the height of the tree:
Balanced tree: height ≈ log(N)
Skewed tree: height = N
No additional data structures are used besides recursion.

Total Space Complexity :-
Best Case: O(log N) → For a perfectly balanced tree.
Worst Case: O(N) → For a completely skewed tree.
Overall: O(H) where H is the height of the tree
