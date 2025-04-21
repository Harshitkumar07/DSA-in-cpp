** Leetcode Problem 938 :- **

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

Example 1:
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

** Code : - **

class Solution {
public:
    void solve(TreeNode* root, int low, int high, int& sum) {
        if (!root) {
            return;
        }
        if (root->val >= low && root->val <= high) {
            sum = sum + root->val;
        }
        if (root->val > low) {
            solve(root->left, low, high, sum);
        }
        if (root->val < high) {
            solve(root->right, low, high, sum);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        solve(root, low, high, sum);
        return sum;
    }
};

** Time Complexity :- **
    
Step 1: Recursive Tree Traversal
The function recursively explores the binary search tree (BST) based on comparisons with low and high.
At each node, it checks whether the value is within the range and selectively traverses left or right subtrees.
In the best case, many branches are pruned due to BST properties, minimizing traversal.

Best Case:
If all nodes are outside the range, only a few recursive calls are made.
Time complexity reduces to O(log n) in a balanced tree.

Worst Case:
If all nodes lie within the range, all nodes must be visited.
In this case, time complexity becomes O(n), where n is the total number of nodes.

Total Time Complexity :-
Best Case: O(log n)
Worst Case: O(n)

** Space Complexity :- **
    
Step 1: Recursion Stack
Depends on the height of the tree, as the function uses recursion.
In a balanced BST, the height is log n.
In a skewed tree, the height can be up to n.

Step 2: Variables
A few integer variables like sum are used — all are constant space.

Total Space Complexity :-
Best Case: O(log n) (balanced BST)
Worst Case: O(n) (skewed BST)
No extra space used beyond recursion → Auxiliary Space: O(1)
