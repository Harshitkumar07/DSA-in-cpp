** Leetcode Problem 100 :- **

Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value. 

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false

** Code :- **

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

** Time Complexity :- **
    
    
Step 1: Recursively Traverse Both Trees
The algorithm performs a depth-first traversal on both input binary trees (p and q) simultaneously.

For each recursive call:
It checks if both nodes are nullptr.
It compares the current node values from p and q.
It recursively checks the left and right subtrees.
Each node in both trees is visited once, and constant-time operations are performed during each visit.

Total Time Complexity :-
Best Case: O(N) → If both trees are identical, the algorithm will traverse all nodes exactly once.
Worst Case: O(N) → Even if the trees differ at the last node, the algorithm has to compare all corresponding nodes up to that point.
Overall: O(N) (Linear Time Complexity where N is the number of nodes in the tree)

** Space Complexity :- **
    
Step 1: Recursion Stack
The function uses recursive calls, which consume stack space equal to the height of the tree.
For a completely balanced binary tree, the height is log N.
For a completely skewed binary tree (like a linked list), the height is N.
There are no additional data structures used—only the recursive call stack.

Total Space Complexity :-
Best Case: O(log N) → If both trees are balanced, the recursion stack only goes as deep as the height.
Worst Case: O(N) → If the trees are skewed, the stack may go as deep as the number of nodes.
Overall: O(H) (Linear Space Complexity in terms of tree height H, which can be up to N)
