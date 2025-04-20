** Leetcode Problem 783 :- **

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

** Code :- **

class Solution {
public:
    TreeNode* prev = nullptr;
    void solve(TreeNode* root, int& diff) {
        if (root == nullptr) {
            return;
        }
        solve(root->left, diff);
        if (prev) {
            diff = min(diff, root->val - prev->val);
        }
        prev = root;
        solve(root->right, diff);
    }
    int minDiffInBST(TreeNode* root) {
        int diff = INT_MAX;
        solve(root, diff);
        return diff;
    }
};

** Time Complexity :- **
    
Step 1: In-order Traversal of the BST
The algorithm performs an in-order traversal, visiting each node exactly once.

For each node:
It checks and updates the minimum difference using constant-time operations.
No node is revisited or skipped.

Total Time Complexity :-
Best Case: O(n) — Even if the BST is perfectly balanced, each node must be visited once.
Worst Case: O(n) — In the case of a skewed tree (e.g., all nodes to one side), traversal still visits all nodes.
Overall: O(n), where n is the number of nodes in the BST.

** Space Complexity :- **
    
Step 1: Recursion Stack
The space used by the recursive calls depends on the height of the tree.
In a balanced tree, the height is log n, so the stack space is O(log n).
In a skewed tree, the height is n, resulting in O(n) stack space.

Step 2: Auxiliary Variables
Only a constant amount of extra space is used to track the previous node (prev) and the minimum difference (diff).

Total Space Complexity :-
Best Case: O(log n) — For a balanced BST.
Worst Case: O(n) — For a completely unbalanced or skewed tree.
Overall: O(h), where h is the height of the tree.
