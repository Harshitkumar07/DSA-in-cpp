** Leetcode Problem 1700 :- **

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. 
All students stand in a queue. Each student either prefers square or circular sandwiches.
The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:
If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.
You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). 
Return the number of students that are unable to eat.

Example 1:
Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0 
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.

Example 2:
Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3

** Code :- **

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue q(deque<int>(students.begin(), students.end()));
        int index = 0, cnt = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr != sandwiches[index]) {
                cnt++, q.push(curr);
            } else {
                cnt = 0, index++;
            }
            if (cnt == q.size()) {
                break;
            }
        }
        return q.size();
    }
};

** Time Complexity :- **

Step 1: Initializing the Queue
Converting the students vector into a deque and initializing a queue from it:
This operation takes O(n) time, where n is the number of students.

Step 2: Simulating the Sandwich Distribution
The while-loop runs until:
All students are served (queue becomes empty), or
No student wants the current top sandwich (i.e., cnt == q.size()).

In each iteration:
One student is processed (front is popped, possibly pushed back), and the index is updated if a sandwich is taken.
In the worst case, each student can be pushed back to the queue multiple times until the loop condition cnt == q.size() is met.

Worst-case scenario:
Every student fails to take the sandwich and is pushed back. This can happen at most n consecutive times before cnt == q.size() ends the loop.

Total Time Complexity :-
Best Case: O(n) – If all students take sandwiches in order.
Worst Case: O(n²) – If each student cycles through the queue multiple times before termination.
Overall: O(n²) in the worst case.

** Space Complexity :- **
    
Step 1: Queue Usage
A queue is used to hold up to n students.

Step 2: Sandwich Array
The sandwiches array is not modified and takes O(n) space.

Total Space Complexity :-
Overall: O(n)
