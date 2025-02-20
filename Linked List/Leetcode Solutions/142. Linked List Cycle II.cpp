** Leetcode Problem 142 :- **

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

** Code :- **

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
        if (!isCycle) {
            return NULL;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

** Time Complexity :- **
     
Cycle Detection Phase (Floyd’s Cycle Detection Algorithm) :
The algorithm uses two pointers:
slow moves one step at a time.
fast moves two steps at a time.
If there is no cycle, fast reaches NULL in O(n) time.
If a cycle exists, slow and fast meet inside the cycle in O(n) time.
Finding the Start of the Cycle :
Once a cycle is detected, slow is reset to head.
Both slow and fast move one step at a time until they meet again at the cycle’s start.
This takes at most O(n) additional steps.
Total Time Complexity :
Best Case: O(n) → If no cycle exists, fast reaches NULL in O(n) time.
Worst Case: O(n) → If a cycle exists, detecting and finding its start takes at most O(n) + O(n) = O(n).
Overall Complexity: O(n).

** Space Complexity :- **
    
Auxiliary Variables (slow, fast, isCycle) :
The function only uses three pointers: slow, fast, and a boolean flag isCycle.
These require O(1) space.
No Extra Data Structures :
The function does not use extra storage like a hash table or array.
The input linked list is modified in-place.
Total Space Complexity :
Best Case: O(1) → Uses only a few pointers, which require constant space.
Worst Case: O(1) → No additional data structures are used.
Overall Complexity: O(1).
