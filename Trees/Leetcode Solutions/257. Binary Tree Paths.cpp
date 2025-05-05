** Leetcode Problem 257 :- ** 

Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children. 

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]

** Code :- **

class Solution {
public:
    void solve(TreeNode* node, string currPath, vector<string>& ans) {
        if (node == nullptr) {
            return;
        }
        currPath += to_string(node->val);
        if (!node->left && !node->right) {
            ans.push_back(currPath);
        } else {
            currPath += "->";
            solve(node->left, currPath, ans);
            solve(node->right, currPath, ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
};

** Time Complexity :- **
    
    
Step 1: Tree Traversal
The function performs a Depth-First Search (DFS) on the binary tree.
It visits every node exactly once, appending the value of the current node to the path string.
So if there are n nodes in the tree, the DFS takes O(n) time.

Step 2: String Building
At each leaf node, the complete path string is created and added to the result.
In the worst case, each path string has a length proportional to the height of the tree (h).
If there are L leaf nodes, and each path takes O(h) time to build, then building strings takes O(L × h) time.

Total Time Complexity :-
Let n = total nodes
Let h = height of the tree
Let L = number of leaves
Overall: O(n + L × h)
This simplifies to O(n × h) in the worst case (for highly unbalanced trees).

** Space Complexity :- **
    
Step 1: Call Stack (Due to Recursion)
In the worst case, the recursion stack will store up to h function calls at a time (the height of the tree).
So recursive call stack space is O(h).

Step 2: Result Vector
The result vector stores L strings (one for each path).
Each string can be up to length h, so storing all paths takes O(L × h) space.

Total Space Complexity :-
O(L × h) for the result.
O(h) for the call stack.
Overall: O(L × h)
