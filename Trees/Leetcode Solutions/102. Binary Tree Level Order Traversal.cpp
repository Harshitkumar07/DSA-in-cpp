** Leetcode Problem 102 :- **

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

** Code :- **

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> currLevel;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                currLevel.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Traversing the Tree Using a Queue
The algorithm visits each node exactly once.

For each node:
It is dequeued from the queue.
Its left and right children (if any) are enqueued.
Its value is added to the current level's result.

If there are N nodes in the tree:
Each node enters and leaves the queue once.
Each operation inside the loop takes constant time.

Total Time Complexity :-
Best Case: O(N) → All nodes are visited once.
Worst Case: O(N) → Even for skewed or full trees.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Output Storage
The result vector ans stores all N node values across levels → O(N).

Step 2: Queue Storage
The queue stores up to one level of the tree at a time.
In the worst case (for a complete binary tree), the last level has about N/2 nodes.

Total Space Complexity :-
Best Case: O(1) → If the tree is empty.
Worst Case: O(N) → For complete binary trees with maximum breadth at the last level.
Overall: O(N) (Linear Space Complexity in the worst case)
