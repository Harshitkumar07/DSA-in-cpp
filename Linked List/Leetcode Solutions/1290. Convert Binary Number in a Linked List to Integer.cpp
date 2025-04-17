** Leetcode Probelm 1290 : - **

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.
The most significant bit is at the head of the linked list. 

Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:
Input: head = [0]
Output: 0

** Code :- **

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head != nullptr) {
            ans = ans * 2 + head->val;
            head = head->next;
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the Linked List
The algorithm iterates through each node in the linked list exactly once.

For each node, it performs a constant-time operation:
ans = ans * 2 + head->val.

Total Time Complexity :-
Let n be the number of nodes in the linked list.

Best Case: O(n) – Processes each node once.
Worst Case: O(n) – Processes each node once, no early termination.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Auxiliary Variables
The algorithm uses:
An integer variable ans to store the final result.
A pointer head which is already given as an input (no extra memory allocation).
No additional data structures are used.

Total Space Complexity :-
Overall: O(1) – Constant space usage.
