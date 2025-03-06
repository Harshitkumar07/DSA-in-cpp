** Leetcode Problem 24 :- **

Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]

** Code :- **

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *first = head, *sec = head->next, *prev = nullptr;

        while (first != nullptr && sec != nullptr) {
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;
            if (prev != nullptr) {
                prev->next = sec;
            } else {
                head = sec;
            }
            // update node for next iterations
            prev = first;
            first = third;
            if (third != nullptr) {
                sec = third->next;
            } else {
                sec = nullptr;
            }
        }
        return head;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the Linked List
The algorithm traverses the linked list once, swapping adjacent nodes in pairs.
Each swap operation modifies only a few pointers in O(1) time.
Since we process n/2 pairs in the worst case, the total complexity remains O(n).
Total Time Complexity :
Best Case: O(1) → If the list has 0 or 1 node, it returns immediately.
Worst Case: O(n) → If there are n nodes, the loop runs n/2 times (still O(n) overall).
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Modifications :
The function modifies the linked list in place, without using additional data structures.
Only a few pointer variables (first, sec, prev, third, head) are used.
Total Space Complexity :
O(1) (Constant Space)
