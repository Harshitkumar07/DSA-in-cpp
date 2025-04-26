** Leetcode Problem 404 :- ** 

Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node. 

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0

** Code :- **

class Solution {
public:
    int solve(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int sum = 0;
        if (node->left && !node->left->left && !node->left->right) {
            sum += node->left->val;
        }
        sum += solve(node->left);
        sum += solve(node->right);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) { 
        return solve(root); 
    }
};

** Time Complexity :- **
    
Step 1: Traversing the Tree
The function solve recursively traverses the entire binary tree.
Each node is visited exactly once.

At each node:
It checks if the left child exists and whether it is a leaf (both left and right pointers are nullptr).
Adds the left leaf value to the sum if the condition is true.
Recursively moves to the left and right subtrees.

Total Time Complexity :-
O(n), where n is the number of nodes in the binary tree.

** Space Complexity :- **
    
Step 1: Recursion Stack
The recursion uses space proportional to the height of the binary tree.
In the best case (completely balanced tree), the height is O(log n).
In the worst case (completely skewed tree), the height is O(n).

Step 2: Additional Space
Apart from the recursion stack, only a few integer variables (sum) are used, which are O(1).

Total Space Complexity :-
Best Case: O(log n) (for balanced trees)
Worst Case: O(n) (for skewed trees)

Summary:
Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree (O(log n) best case, O(n) worst case)
