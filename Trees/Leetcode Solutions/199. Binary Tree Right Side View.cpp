** Leetcode Problem 199 :- **

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]

Example 3:
Input: root = [1,null,3]
Output: [1,3]

Example 4:
Input: root = []
Output: []

** Code :- **

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int level = q.size();
            for (int i = 0; i < level; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (i == level - 1) {
                    ans.push_back(curr->val);
                }
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Traversing the Tree Level by Level
The algorithm performs a Breadth-First Search (BFS) using a queue.
Each node in the binary tree is pushed into the queue once and popped once.

For each node:
Check if it's the last node at its level (simple index comparison).
Push its left and right children (if they exist) into the queue.

Total Time Complexity:
O(n), where n is the total number of nodes in the tree.

** Space Complexity :- **
    
Step 1: Queue Usage
The queue holds nodes at each level.
In the best case (completely balanced tree), the maximum number of nodes at the last level is about n/2.
In the worst case (completely skewed tree), the queue may contain up to n nodes at once (if it's a straight line).

Step 2: Answer Storage
The result vector ans stores exactly one value per level.
In the worst case (tree height = n), it can store up to n values.

Total Space Complexity:
O(n) for the queue in the worst case.
O(h) for the ans vector, where h is the height of the tree (at most O(n)).

Thus, Overall Space Complexity: O(n).
