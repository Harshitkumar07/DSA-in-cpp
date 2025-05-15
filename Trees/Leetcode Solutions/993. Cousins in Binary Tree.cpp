** Leetcode Problem 993 :- **

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
Two nodes of a binary tree are cousins if they have the same depth with different parents.
Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1. 

Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

** Code :- **

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            bool foundX = false, foundY = false;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->val == x) {
                    foundX = true;
                }
                if (node->val == y) {
                    foundY = true;
                }
                if (node->left && node->right) {
                    int l = node->left->val, r = node->right->val;
                    if ((l == x && r == y) || (l == y && r == x)) {
                        return false;
                    }
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (foundX && foundY) {
                return true;
            }
            if (foundX || foundY) {
                return false;
            }
        }
        return false;
    }
};

** Time Complexity :- **
    
Step 1: Breadth-First Search (BFS)
The algorithm performs a level-order traversal (BFS) using a queue.
Each node is visited exactly once.

Step 2: Per Node Processing
For each node:
Constant-time operations are performed: value comparisons, pointer accesses, and enqueue operations.
In the worst case, we examine all nodes until both x and y are found.

Total Time Complexity :-
O(n), where n is the number of nodes in the binary tree.

** Space Complexity :- **
    
Step 1: Queue Usage
A queue is used for level-order traversal.
In the worst case (a full binary tree), the queue may contain up to n/2 nodes at the deepest level.

Step 2: Other Variables
A few boolean and integer variables (foundX, foundY, size, etc.) are used, which require constant space.

Total Space Complexity :- 
O(n) in the worst case due to the queue storing up to half the tree’s nodes.
