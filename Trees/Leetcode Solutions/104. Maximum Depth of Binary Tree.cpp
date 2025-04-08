** Leetcode Problem 104 :- **

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. 

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

** Code :- **

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }
};

** Time Complexity :- **
    
Step 1: Recursive Traversal
The function visits every node once to compute the depth.
For each node, it recursively calls maxDepth on the left and right subtrees.
Each recursive call does a constant amount of work (1 comparison and 1 addition).
If the tree has N nodes, every node is visited once.

Total Time Complexity :-
Best Case: O(N) → All nodes are visited.
Worst Case: O(N) → For skewed trees (e.g., a linked list).
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **

Step 1: Recursive Call Stack
The maximum depth of the recursion stack depends on the height of the tree:Best case: Balanced tree → height = log(N)
Worst case: Skewed tree → height = N
There’s no extra space used except for the recursion stack.

Total Space Complexity :-
Best Case: O(log N) → For a perfectly balanced tree.
Worst Case: O(N) → For a skewed tree.
Overall: O(H) where H is the height of the tree (i.e., recursive depth)
