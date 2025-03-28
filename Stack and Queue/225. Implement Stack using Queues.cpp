** Leetcode Problem 225 :- **

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
Implement the MyStack class:
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

Example 1:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]
Explanation :
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

** Code :- **

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x) {
        // copy elements of q1 in q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // push the element
        q1.push(x);
        // copy elemnets of q2 in q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() { return q1.front(); }

    bool empty() { return q1.empty(); }
};

** Time Complexity :- **
    
Push Operation (push(x))
The algorithm moves all elements from q1 to q2 (O(N) time).
Inserts x into q1 (O(1) time).
Moves all elements from q2 back to q1 (O(N) time).
Since every element is transferred twice, the total time complexity is O(N).
Pop Operation (pop())
Removing the front element of q1 takes O(1) time.
Top Operation (top())
Retrieving the front element of q1 takes O(1) time.
Empty Operation (empty())
Checking whether q1 is empty takes O(1) time.

Total Time Complexity :-
Operation	Time Complexity
Push	O(N)
Pop	O(1)
Top	O(1)
Empty	O(1)

** Space Complexity :- **
    
Step 1: Storage for Queues
Two queues, q1 and q2, are used.
The total space used is O(N), where N is the number of elements in the stack.

Total Space Complexity :-
Best Case: O(N) → Space depends on the number of elements stored. 
Worst Case: O(N) → If the stack has N elements, the queues hold N elements.
Overall: O(N) (Linear Space Complexity)
