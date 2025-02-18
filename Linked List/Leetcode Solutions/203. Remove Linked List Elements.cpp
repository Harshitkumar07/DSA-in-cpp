** Leetcode Problem 203 :- **

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []

** Code :- **

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

** Time Complexity :- **
    
Iterating Through the Linked List :
The algorithm traverses the entire linked list once to remove nodes with the target value.
Each node is visited only once.
Total Time Complexity :
Since we traverse all n nodes once, the time complexity is O(n), where n is the number of nodes in the linked list.

** Space Complexity :- **
    
Constant Extra Space :
The algorithm only uses a few pointer variables (head and temp).
No additional data structures are used.
Total Space Complexity :
Since only O(1) extra space is used, the space complexity is O(1).
