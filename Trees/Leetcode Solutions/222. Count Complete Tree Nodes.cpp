** Leetcode Problem 222 :- **

Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity. 

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1

** Code :- **

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return 1 + left + right;
    }
};

** Time Complexity :- **
    
Step 1: Recursive Tree Traversal
The algorithm uses recursion to visit every node in the binary tree.
For each node, it makes two recursive calls: one for the left child and one for the right child.
After both recursive calls return, it computes the total by summing left, right, and 1 for the current node.
Let N be the total number of nodes in the tree.
Each node is visited exactly once.

Total Time Complexity :-
Best Case: O(N) → Tree with all nodes visited once.
Worst Case: O(N) → Skewed or balanced, all nodes still processed.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
The space used is due to the recursive call stack.
In the best case (balanced binary tree), the maximum depth of recursion is O(log N).
In the worst case (completely skewed tree), the depth is O(N).
No additional data structures are used.

Total Space Complexity :-
Best Case: O(log N)
Worst Case: O(N)
Overall: O(H), where H is the height of the tree.
