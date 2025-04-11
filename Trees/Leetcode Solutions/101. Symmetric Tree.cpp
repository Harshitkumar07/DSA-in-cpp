** Leetcode Problem 101 :- **

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center). 

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false

** Code :- **

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        return (left->val == right->val) && isMirror(left->left, right->right) 
            && isMirror(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isMirror(root->left, root->right);
    }
};

** Time Complexity :- **
    
    
Step 1: Recursive Mirror Check
The algorithm uses a helper function isMirror to recursively compare the left and right subtrees of the binary tree:

For each pair of nodes (left, right):
It checks if both are nullptr → returns true.
If only one is nullptr → returns false.

If values match → recursively compares:
left->left with right->right
left->right with right->left
Each node in the binary tree is visited exactly once, and for each node pair, a constant-time comparison is made.

Total Time Complexity :-
Best Case: O(N) → Even if symmetry breaks early, in the worst case the function still needs to inspect all nodes up to the point of mismatch.
Worst Case: O(N) → Every node in the tree is visited recursively to check mirror symmetry.
Overall: O(N) (Linear Time Complexity, where N is the number of nodes in the binary tree)

** Space Complexity :- **
    
Step 1: Recursion Stack
The algorithm uses recursion, and the depth of the recursion stack depends on the height of the tree:
For a perfectly balanced binary tree, the height is log N.
For a skewed binary tree, the height is N.
No additional data structures are used beyond the call stack.

Total Space Complexity :-
Best Case: O(log N) → If the tree is balanced, the recursive stack grows logarithmically.
Worst Case: O(N) → If the tree is completely skewed, the recursive stack depth reaches N.
Overall: O(H) where H is the height of the binary tree. In the worst case, O(N).
