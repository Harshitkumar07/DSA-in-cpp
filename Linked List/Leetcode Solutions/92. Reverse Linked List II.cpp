** Leetcode Problem 92 :- **

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

** Code :- **

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* next = NULL;
        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

** Time Complexity :- **
    
Finding the Left Position (prev Pointer Traversal) :
The algorithm first traverses the list to reach the left position.
This requires O(left) time.
Reversing the Sublist :
The reversal process uses the iterative in-place reversal method, where each node in the range [left, right] is repositioned.
The loop runs (right - left) times, which is O(right - left).
Total Time Complexity :
Best Case: O(n) → If left = 1 and right = n, the entire list is reversed.
Worst Case: O(n) → If left and right are far apart, the traversal and reversal still take O(n).
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Modifications :
The algorithm modifies the list in place without extra space.
A few pointer variables (prev, curr, next, dummy) are used.
Dummy Node Allocation :
A dummy node is allocated at the beginning, but it is deleted before returning the result, so it does not contribute to extra space usage.
Total Space Complexity :
O(1) (Constant Space)
