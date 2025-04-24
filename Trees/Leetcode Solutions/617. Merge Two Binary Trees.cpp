** Leetcode Problem 617 :- **

You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. 
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.
Return the merged tree.
Note: The merging process must start from the root nodes of both trees. 

Example 1:
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

Example 2:
Input: root1 = [1], root2 = [1,2]
Output: [2,2]

** Code :- **

class Solution {
public:
    TreeNode* solve(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = solve(root1->left, root2->left);
        root1->right = solve(root1->right, root2->right);
        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};

** Time Complexity :- **
    
Step 1: Recursive Traversal of Both Trees
The function performs a recursive traversal of both trees simultaneously.
At each corresponding node in root1 and root2, it:
Adds the values.
Recursively merges the left and right children.

Total Nodes Visited:
In the worst case, all nodes of both trees are visited.
Let n1 be the number of nodes in root1, and n2 be the number of nodes in root2.

Overall Time Complexity :-
O(min(n1, n2)) — since recursion stops when either tree runs out of nodes.
If trees are of equal size: O(n), where n is the number of nodes in the trees.

** Space Complexity :- **
    
Step 1: Recursion Stack
The recursion depth depends on the height of the trees.
In the best case (balanced trees), the height is log n.
In the worst case (skewed trees), the height is n.

Step 2: In-Place Merge
No new tree is created — the merge happens in-place on root1.
No additional memory is used for storing tree nodes.

Overall Space Complexity :-
O(h), where h is the height of the tree (due to recursion stack).
Best Case: O(log n)
Worst Case: O(n)
