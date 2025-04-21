** Leetcode Problem 226 :- **

Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []

** Code :- **

class Solution {
public:
    void solve(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root != nullptr) {
            swap(root->left, root->right);
        }
        solve(root->left);
        solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) { 
        solve(root); 
        return root;
    }
};

** Time Complexity :- **
    
Step 1: Traversing Each Node
The function recursively visits every node in the binary tree exactly once.

At each node:
It performs a constant-time operation — swapping the left and right child nodes.

Total Time Complexity :-
Best Case: O(n) — All nodes must be visited even if the tree is already symmetric.
Worst Case: O(n) — For a skewed or completely unbalanced tree.
Overall: O(n), where n is the number of nodes in the tree.

** Space Complexity :- **
    
Step 1: Recursion Stack
The space used depends on the height of the tree due to recursion.
For a balanced tree, the recursion depth is O(log n).
For a skewed tree, the depth becomes O(n).

Step 2: Auxiliary Space
No additional data structures are used—only the recursion stack and constant space for function calls.

Total Space Complexity :-
Best Case: O(log n) — In a balanced binary tree.
Worst Case: O(n) — In a skewed binary tree.
Overall: O(h), where h is the height of the tree.
