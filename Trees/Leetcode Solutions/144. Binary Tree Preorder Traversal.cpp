** Leetcode Problem 144 :- **

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

** Code :- **

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Preorder Traversal (Recursive Function)
The function preorder visits each node exactly once.
For each node, a constant amount of work is done:
The node’s value is added to the result vector.
Recursive calls are made for the left and right children.
If the tree has N nodes, then.
The recursive function will be called N times.
No node is revisited.

Total Time Complexity :-
Best Case: O(N) → Every node is visited once.
Worst Case: O(N) → Same as best case, applies to skewed or balanced trees.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Output Storage
A vector ans is used to store the preorder traversal.
It will contain exactly N elements, where N is the number of nodes in the tree.
This contributes O(N) space.

Step 2: Recursive Call Stack
The recursion stack will use additional memory depending on the height of the tree:
Best Case (balanced tree): Height = log(N), so stack space is O(log N).
Worst Case (completely skewed tree): Height = N, so stack space is O(N).

Total Space Complexity :-
Best Case: O(N) (vector) + O(log N) (stack) = O(N)
Worst Case: O(N) (vector) + O(N) (stack) = O(N)
Overall: O(N) (Linear Space Complexity)
