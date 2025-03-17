** Leetcode Problem 155 :- **

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input :
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output :
[null,null,null,null,-3,null,0,-2]

Explanation :
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

** Code :- **

class MinStack {
public:
    stack<pair<int, int>> st; // val,minVal
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int minVal = min(val, st.top().second);
            st.push({val, minVal});
        }
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

** Time Complexity :- **
    
Step 1: Push Operation
Each push operation inserts a pair (val, minVal) onto the stack.
The minimum value at any step is determined in O(1) time using min(val, st.top().second).
Since pushing a pair onto a stack is O(1), the overall push operation takes O(1) time.
Step 2: Pop Operation
Removing the top element from the stack takes O(1) time.
Step 3: Top Operation
Retrieving the top element’s value takes O(1) time.
Step 4: GetMin Operation
Since each push operation stores the minimum value along with the element, retrieving the minimum takes O(1) time.

Total Time Complexity :
Push: O(1)
Pop: O(1)
Top: O(1)
GetMin: O(1)
Overall: O(1) per operation (Constant Time Complexity)

Space Complexity :

Step 1: Storage for Stack Elements
The stack stores each element as a pair (val, minVal).
In the worst case (when all elements are unique and decreasing), the stack holds N pairs, requiring O(N) space.

Total Space Complexity :
Best Case: O(1) → If very few elements are stored.
Worst Case: O(N) → If N elements are pushed onto the stack.
Overall: O(N) (Linear Space Complexity)
