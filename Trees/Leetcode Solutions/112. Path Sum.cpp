** Leetcode Problem 112 :- **

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children. 

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

Example 3:
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

** Code :- **

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        int ans = targetSum - root->val;
        return hasPathSum(root->left, ans) || hasPathSum(root->right, ans);
    }
};

** Time Complexity :- **
    
Step 1: Traversing the Tree
The algorithm performs a Depth-First Search (DFS) traversal of the binary tree.
In the worst case, it needs to visit every node once to find a path or determine that no valid path exists.

For each node:
Check if it is a leaf node.
Update the targetSum by subtracting the node's value.
Recursively call the function on the left and right child nodes.

Total Time Complexity:
O(n), where n is the total number of nodes in the binary tree.

** Space Complexity :- **
    
Step 1: Recursive Call Stack
The algorithm uses the call stack for recursion.
In the worst case (if the tree is skewed), the recursion depth could be n (all nodes form a single branch).
In the best case (balanced binary tree), the recursion depth would be proportional to the height, which is O(log n).

Total Space Complexity:
Best Case: O(log n) (balanced tree)
Worst Case: O(n) (skewed tree)
