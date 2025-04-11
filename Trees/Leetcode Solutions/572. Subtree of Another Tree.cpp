** Leetcode Problem 572 :- **

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself. 

Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

** Code :- **

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL)
            return false;
        if (isSameTree(root, subRoot))
            return true;
        return (isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot));
    }
};

** Time Complexity :- **
    
Step 1: isSubtree Traversal
The function checks each node of the main tree (root) to see if a subtree starting from that node matches subRoot.
In the worst case, it traverses all N nodes in the root tree.

Step 2: isSameTree Comparison
For each node in root, it may call isSameTree which compares it with subRoot.
In the worst case, isSameTree visits all M nodes of subRoot.
So, for each of the N nodes in root, you may compare up to M nodes of subRoot.

Total Time Complexity :-
Best Case: O(N) → If a match is found early in the traversal.
Worst Case: O(N × M) → When isSameTree is called at every node of root, and each call compares the entire subRoot.
Overall: O(N × M) (where N = nodes in root, M = nodes in subRoot)

** Space Complexity :- **
    
Step 1: Recursion Stack
The space complexity is determined by the recursive call stack depth.

In the worst case, both isSubtree and isSameTree can go as deep as the height of the tree:
For a skewed tree, the height is O(N).
For a balanced tree, the height is O(log N).

Step 2: No Extra Data Structures
No additional memory beyond the recursion stack is used.

Total Space Complexity :-
Best Case: O(log N + log M) → For balanced trees.
Worst Case: O(N + M) → For skewed trees, both root and subRoot.
Overall: O(H1 + H2) where H1 and H2 are the heights of root and subRoot.
