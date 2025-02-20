** Leetcode Problem 141 :- **

Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false. 

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

** Code :- **

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

** Time Complexity :- **
    
Detecting a Cycle in the Linked List :
The algorithm uses the Floyd’s Cycle Detection Algorithm (Tortoise and Hare Algorithm).
It employs two pointers:
slow moves one step at a time.
fast moves two steps at a time.

Case 1: No Cycle in the List
If the linked list does not have a cycle, the fast pointer will reach NULL in O(n) time.
This is because fast moves twice as fast as slow, and the traversal stops once fast reaches the end.

Case 2: Cycle Exists in the List
If the linked list has a cycle, the two pointers will eventually meet inside the cycle.
The worst-case scenario occurs when the cycle is at the end of the list.
The distance between slow and fast decreases by 1 per iteration inside the cycle.
Since fast moves twice as fast as slow, they will meet in O(n) iterations.
Total Time Complexity :
Best Case: O(n) → If there is no cycle, fast reaches NULL in O(n) time.
Worst Case: O(n) → If there is a cycle, slow and fast meet in O(n) time.
Overall Complexity: O(n) since the loop runs at most O(n) times.

** Space Complexity :- **

Auxiliary Variables (slow and fast) :
The function only uses two pointers (slow and fast).
These require O(1) space.
No Extra Data Structures :
The function operates directly on the input linked list.
No additional storage (such as a hash set or extra array) is used.
Total Space Complexity :
Best Case: O(1) → Uses only two pointers, which require constant space.
Worst Case: O(1) → No extra space is used beyond the input list.
Overall Complexity: O(1).
