** Leetcode Problem 61 :- **

Given the head of a linked list, rotate the list to the right by k places. 

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

** Code :- **

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        k = k % len;
        if (k == 0) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newHead;
    }
};

** Time Complexity :- **
    
    
Finding the Length of the List :
The algorithm traverses the list once to determine its length (len).
This takes O(n) time.
Adjusting k :
The value of k is updated using k = k % len, which takes O(1) time.
Finding the New Head :
The algorithm uses two pointers (slow and fast):
fast moves k steps ahead (O(k)).
Then, both slow and fast move together until fast reaches the end (O(n - k)).
Since k < n, the total traversal in this step is O(n).
Updating the List :
The list is rotated by modifying pointers, which takes O(1).
Total Time Complexity :
Best Case: O(n) → If k = 0 or k is a multiple of n, no rotation is needed.
Worst Case: O(n) → If k is large but not a multiple of n, the full traversal is required.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Modifications :
The function modifies the linked list in-place without extra storage.
Only a few pointers (slow, fast, tail, newHead) are used.
Total Space Complexity :
O(1) → No additional data structures are used, so space usage is constant.
