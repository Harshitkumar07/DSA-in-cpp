** Leetcode Problem 530 :- **

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree. 

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

** Code : - **

class Solution {
public:
    TreeNode* temp = nullptr;
    void solve(TreeNode* root, int& diff) {
        if (root == nullptr) {
            return;
        }
        solve(root->left, diff);
        if (temp) {
            diff = min(diff, abs(root->val - temp->val));
        }
        temp = root;
        solve(root->right, diff);
    }
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        solve(root, diff);
        return diff;
    }
};

** Time Complexity :- **
    
Step 1: In-order Traversal (solve function)
The function solve performs an in-order traversal of the binary search tree (BST). In-order traversal visits each node exactly once, which takes linear time.
Number of nodes = n
Visiting each node = O(1)
Total = O(n)

Step 2: Comparison and Difference Calculation
For each visited node (except the first), we compute the absolute difference between the current node and the previous (temp) node. This is a constant-time operation.
Per node = O(1)
Across all nodes = O(n)
Total Time Complexity: O(n)
Where n is the total number of nodes in the BST.

** Space Complexity :- **
    
Step 1: Recursion Stack Space
The traversal is recursive, and the depth of the recursive call stack depends on the height of the tree.
In a balanced BST, the height is log(n), so stack space = O(log n)
In the worst case (completely skewed tree), height = n, so stack space = O(n)

Step 2: Extra Variables
The algorithm uses only a few auxiliary variables:
An integer diff
A pointer temp to the previously visited node
These take O(1) space.

Total Space Complexity :-
Best/Average Case (balanced tree): O(log n)
Worst Case (skewed tree): O(n)
