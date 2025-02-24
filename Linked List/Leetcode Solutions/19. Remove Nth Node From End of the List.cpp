** Leetcode Problem 19 :- **

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

** Code :- **

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count ++;
            temp = temp->next;
        }
        count = count - n;
        if (count == 0) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode *curr = head, *prev = NULL;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }
};

** Time Complexity :- **
    
First Traversal (Counting Nodes) :
The algorithm first traverses the linked list to count the total number of nodes (count).
This takes O(n) time.
Second Traversal (Finding the Node to Remove) :
The algorithm then traverses again to reach the (count - n)th node.
This also takes O(n) time in the worst case.
Total Time Complexity :
Best Case: O(n) → If n = 1, we still need to traverse the entire list twice.
Worst Case: O(n) → Always requires two passes through the list.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Modifications :
The function modifies the linked list in place using only a few pointer variables (temp, curr, prev).
No extra data structures or recursion are used.
Total Space Complexity :
O(1) (Constant Space)
