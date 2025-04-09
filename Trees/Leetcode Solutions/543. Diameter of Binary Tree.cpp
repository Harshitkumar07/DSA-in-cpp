** Leetcode Problem 543 :- **

Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them. 

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

** Code :- **

class Solution {
public:
    int diameter(TreeNode* root, int& ans) {
        if (!root)
            return 0;
        int left = diameter(root->left, ans);
        int right = diameter(root->right, ans);
        ans = max(ans, left + right);
        return (max(left, right) + 1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        diameter(root, ans);
        return ans;
    }
};

** Time Complexity :- **
    
    
Step 1: Recursive Postorder Traversal of the Tree
The function uses a helper function diameter to perform a postorder traversal of the binary tree.

For each node:
It recursively computes the height of the left and right subtrees.
Updates the diameter by taking the sum of left and right heights.
Returns the height of the current subtree (max(left, right) + 1).
Each node is visited exactly once, and each operation per node takes constant time.

Total Time Complexity :-
Best Case: O(N) → Even if the tree is empty or has only one node, the traversal still visits each node once.
Worst Case: O(N) → For an unbalanced or skewed tree, each node is visited in a linear manner.
Overall: O(N) (Linear Time Complexity, where N is the number of nodes in the binary tree)

** Space Complexity :- **
    
Step 1: Recursion Stack
The space complexity is determined by the maximum depth of the recursive call stack.

In a balanced binary tree, the height is log N.
In a skewed binary tree, the height is N.
No extra space is used except for the recursion call stack and a single int variable (ans) to store the maximum diameter.

Total Space Complexity :-
Best Case: O(log N) → If the tree is balanced, the recursion stack grows logarithmically.
Worst Case: O(N) → If the tree is skewed (like a linked list), the recursion stack depth reaches N.
Overall: O(H), where H is the height of the binary tree. In the worst case, O(N).
