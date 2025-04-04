** Leetcode Problem 2073 :- **

There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.
You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].
Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. 
If a person does not have any tickets left to buy, the person will leave the line.
Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

Example 1:
Input: tickets = [2,3,2], k = 2
Output: 6
Explanation:
The queue starts as [2,3,2], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
Continuing this process, the queue becomes [2,1,2] at 2 seconds.
Continuing this process, the queue becomes [1,2,1] at 3 seconds.
Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
Continuing this process, the queue becomes [1,1] at 5 seconds.
Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.

Example 2:
Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
The queue starts as [5,1,1,1], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [1,1,1,4] at 1 second.
Continuing this process for 3 seconds, the queue becomes [4] at 4 seconds.
Continuing this process for 4 seconds, the queue becomes [] at 8 seconds. The kth person has bought all their tickets, so return 8.

** Code :- **

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }
        int time = 0;
        while (tickets[k] != 0) {
            tickets[q.front()]--;
            if (tickets[q.front()]) {
                q.push(q.front());
            }
            q.pop();
            time++;
        }
        return time;
    }
};

** Time Complexity :- **

Step 1: Initializing the Queue
We iterate through the tickets array to push all indices into the queue.
Time Complexity: O(N).

Step 2: Processing the Queue
Each iteration processes the person at the front of the queue.
We decrement their ticket count.
If their count is still greater than zero, we push them back into the queue.
The loop continues until tickets[k] == 0.
In the worst case:
Each person is processed min(tickets[i], tickets[k]) times.
Total operations: O(Σ min(tickets[i], tickets[k])).
In the worst case, this is O(N × max(tickets)).

Total Time Complexity :-
Best Case: O(N) → If tickets[k] is small, the loop exits quickly.
Worst Case: O(N × max(tickets)) → If many people have high ticket counts.
Overall: O(N × max(tickets)).

** Space Complexity :- **

Step 1: Queue Storage
The queue stores at most N elements at any time.
Worst case: O(N) space.

Step 2: Extra Variables
We use a few integer variables (time).
Total extra space: O(1).

Total Space Complexity :-
Best Case: O(1) → If tickets[k] is small, minimal queue operations.
Worst Case: O(N) → If everyone stays in the queue for a long time.
Overall: O(N) (Linear Space Complexity in Terms of Number of People).
