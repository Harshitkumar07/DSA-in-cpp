** Leetcode Problem 225 :- **

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

Example 1:
Input :
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output :
[null, null, null, 1, 1, false]
Explanation :
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
** Code :- **

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {}

    void push(int x) {
        // copy elements of st1 in st2
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        // push the element
        st1.push(x);
        // copy elemnets of st2 in st1
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop() {
        int ans = st1.top();
        st1.pop();
        return ans;
    }

    int peek() { return st1.top(); }

    bool empty() { return st1.empty(); }
};

** Time Complexity :- **

Push Operation (push(x))
The algorithm moves all elements from st1 to st2 (O(N) time).
Inserts x into st1 (O(1) time).
Moves all elements back from st2 to st1 (O(N) time).
Since each element is transferred twice, the total time complexity is O(N).
Pop Operation (pop())
Removing the top element from st1 takes O(1) time.
Peek Operation (peek())
Retrieving the top element from st1 takes O(1) time.
Empty Operation (empty())
Checking whether st1 is empty takes O(1) time.

Total Time Complexity :-
Operation	Time Complexity
Push	O(N)
Pop	O(1)
Peek	O(1)
Empty	O(1)

** Space Complexity :- **
    
Step 1: Storage for Stacks
Two stacks, st1 and st2, are used.
The total space used is O(N), where N is the number of elements in the queue.

Total Space Complexity :-
Best Case: O(N) → Space depends on the number of elements stored.
Worst Case: O(N) → If the queue has N elements, the stacks hold N elements.
Overall: O(N) (Linear Space Complexity)
