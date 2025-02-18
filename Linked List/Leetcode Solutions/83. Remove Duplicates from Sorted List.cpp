** Leetcode Problem 83 :- **

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

** Code :- **

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            ListNode* temp = curr->next;
            if (curr->val == temp->val)
                curr->next = temp->next;
            else
                curr = curr->next;
        }
        return head;
    }
};

** Time Complexity :- **
    
Iterating Through the Linked List :
The algorithm traverses the linked list once, visiting each node exactly once.
Total Time Complexity :
Since we process all n nodes only once, the time complexity is O(n), where n is the number of nodes in the linked list.

** Space Complexity :- **

Constant Extra Space :
The algorithm only uses a few pointer variables (curr and temp).
No additional data structures are used.
Total Space Complexity :
Since only O(1) extra space is used, the space complexity is O(1).
