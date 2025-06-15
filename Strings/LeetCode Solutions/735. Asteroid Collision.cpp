** Leetcode Problem 735 :- **

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet. 

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

** Code :- **

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for (int ast : asteroids) {
            while (!stack.empty() && ast < 0 && stack.top() > 0) {
                if (stack.top() < -ast) {
                    stack.pop();
                    continue;
                } else if (stack.top() == -ast) {
                    stack.pop();
                }
                ast = 0;
                break;
            }
            if (ast != 0) {
                stack.push(ast);
            }
        }
        vector<int> ans;
        while (!stack.empty()) {
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

** Time Complexity :- **
    
    
Step 1: Iterating Through Asteroids
The algorithm processes each asteroid in the input vector exactly once.
For each asteroid, it checks conditions to determine if a collision occurs.
In the worst case, multiple elements from the stack can be popped due to collisions.
Each asteroid can be pushed and popped at most once.
Let N be the number of asteroids.
Thus, the total number of operations involving pushing and popping from the stack is bounded by O(N).

Step 2: Building the Result Vector
After processing, the stack is emptied into a result vector.
This takes O(N) time in the worst case.

Step 3: Reversing the Result Vector
Reversing a vector of size up to N takes O(N) time.

Total Time Complexity :-
Best Case: O(N) → Minimal or no collisions, linear traversal and stack operations.
Worst Case: O(N) → Each element is pushed and popped once, then result vector is reversed.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
The algorithm uses:
A stack to store surviving asteroids (up to N elements).
A result vector to store the final answer (up to N elements).
Other variables (ast, ans, loop counters) use constant space.

Total Space Complexity :-
Best Case: O(N) → All asteroids survive; both stack and result vector store N elements.
Worst Case: O(N) → Similar usage.
Overall: O(N) (Linear Space Complexity)
