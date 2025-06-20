** Leetcode Problem 386 :- **

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
You must write an algorithm that runs in O(n) time and uses O(1) extra space.  

Example 1:
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

Example 2:
Input: n = 2
Output: [1,2]

** Code :- **

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int x = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = x;
            if (x * 10 > n) {
                if (x == n) {
                    x /= 10;
                }
                x++;
                while (x % 10 == 0) {
                    x /= 10;
                }
            } else {
                x *= 10;
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Generating Lexicographical Order
The algorithm simulates a pre-order traversal of numbers in a virtual 10-ary tree rooted at 1 through 9.
It fills the result vector ans of size n by choosing the next lexicographical number.
The value x is updated in each iteration based on its current value:
Multiply by 10 to go deeper.
Increment or divide to backtrack as needed.
Each number from 1 to n is added exactly once, and each update to x is a constant-time operation.
Let N be the input number.

Total Time Complexity :-
    
Best Case: O(N)
Worst Case: O(N)
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- 

The algorithm creates a vector ans of size n to store the result.
Other than that, only a few integer variables are used (x, i).

Total Space Complexity :-
Best Case: O(N)
Worst Case: O(N)
Overall: O(N) (Linear Space Complexity)
