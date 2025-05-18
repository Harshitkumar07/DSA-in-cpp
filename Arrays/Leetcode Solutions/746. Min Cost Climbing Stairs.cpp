** Leetcode Problem 746 :- **

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

** Code :- **

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = 0, prev2 = 0;
        for (int i = 2; i <= cost.size(); i++) {
            int curr = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the Cost Array
The algorithm loops from i = 2 to i <= cost.size():
In each iteration, it computes the minimum cost to reach the current step using the previous two step costs.
The loop runs exactly cost.size() - 1 times.
Each operation inside the loop (addition, min, and assignment) is O(1).

Total Time Complexity :-
Best Case: O(N) → Every step must be processed once.
Worst Case: O(N) → All steps are iterated linearly.
Overall: O(N), where N is the number of stairs (i.e., cost.size())

** Space Complexity :- **
    
Step 1: Constant Space Usage
The algorithm uses only three variables:
prev1 (cost to reach previous step)
prev2 (cost to reach two steps back)
curr (cost to reach the current step, used temporarily)
No additional space proportional to the input size is used.

Total Space Complexity :-
Best Case: O(1) → No extra space beyond three variables.
Worst Case: O(1) → Independent of the input size.
Overall: O(1) (Constant Space Complexity)
