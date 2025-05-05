** Leetcode Problem 235 :- **

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).” 

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

** Code :- **

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};

** Time Complexity :- **
    
    
Step 1: Traversing the BST
In the worst case, the function traverses from the root to a leaf.
At each step, it decides whether to go left or right based on the values of p and q.
This follows the properties of a Binary Search Tree, where at each node, the subtree is reduced by half.
Therefore, the time complexity depends on the height of the tree (h):

Best Case (Balanced Tree):
Height h = log n → O(log n)
Worst Case (Skewed Tree):
Height h = n → O(n)

Overall Time Complexity :-
O(h), where h is the height of the tree.

** Space Complexity :- **
    
Step 1: Iterative Traversal 
The function uses no recursion and no additional data structures beyond a few pointers.
Since it's a loop with constant space usage per iteration:

Overall Space Complexity :-
O(1) (constant space)
