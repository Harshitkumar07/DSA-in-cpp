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
    bool isSame(TreeNode* r1, TreeNode* r2) {
        if (r1 == nullptr && r2 == nullptr) {
            return true;
        }
        if (r1 == nullptr || r2 == nullptr) {
            return false;
        }
        if (r1->val != r2->val) {
            return false;
        }
        return isSame(r1->left, r2->left) && isSame(r1->right, r2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (isSame(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

** Time Complexity :- **
    
Step 1: Traversing the root tree
The function isSubtree recursively visits each node of the root tree to check whether the subRoot matches as a subtree.
This traversal takes O(n) time, where n is the number of nodes in root, since each node may be a potential root for subRoot.

Step 2: Comparing subtrees (isSame function)
At each node in root, the function may invoke isSame to compare the subtree rooted at that node with subRoot.
The isSame function itself performs a recursive comparison of two trees, which takes O(m) time in the worst case, where m is the number of nodes in subRoot.

Total Time Complexity :-
Best Case: O(n), if subRoot is found at the root of root or very early in the traversal.
Worst Case: O(n × m), if every node in root is checked and compared with subRoot.

Overall Time Complexity: O(n × m)
Where n = number of nodes in root, and m = number of nodes in subRoot.

** Space Complexity :- **
    
Step 1: Recursion stack for isSubtree and isSame
Both functions are recursive and may go as deep as the height of their respective trees.
In the worst case (skewed trees), the recursion stack may grow up to O(h), where h is the maximum height between root and subRoot.

Step 2: Additional memory
No additional data structures are used that scale with input size. Only a few integer pointers and comparisons are done during recursion.

** Total Space Complexity :- ** 

Best Case: O(1), if the match is found immediately and trees are very shallow.
Worst Case: O(h), where h is the height of the tree (up to O(n) in the worst skewed case).
Overall Space Complexity: O(h)
Where h is the height of the larger tree.
