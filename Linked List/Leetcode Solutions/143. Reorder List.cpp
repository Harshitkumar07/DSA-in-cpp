** Leetcode Problem 143 :- **

You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed. 

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

** Code :- **

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL, *curr = slow->next;
        slow->next = NULL;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        ListNode *first = head, *second = prev;
        while (second) {
            ListNode *temp1 = first->next, *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};

** Time Complexity :- **
    
Step 1: Finding the Middle of the List
The algorithm uses the slow and fast pointer technique to find the middle of the list.
This takes O(n) time.
Step 2: Reversing the Second Half of the List
The second half of the list is reversed in place.
This takes O(n/2) = O(n) time.
Step 3: Merging the Two Halves
The two halves are merged in an alternating fashion.
This takes O(n) time.
Total Time Complexity :
Best Case: O(n) → If the list is already in the desired order, each step still runs in O(n).
Worst Case: O(n) → All three steps (finding the middle, reversing, and merging) execute fully.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Modifications :
The function modifies the linked list in place, using only a few pointer variables (slow, fast, prev, curr, etc.).
No extra data structures or recursion are used.
Total Space Complexity :
O(1) (Constant Space)
