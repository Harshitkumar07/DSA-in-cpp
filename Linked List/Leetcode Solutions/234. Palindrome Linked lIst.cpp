** Leetcode Problem 234 :- **

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

** Code :- **

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        count /= 2;
        ListNode *curr = head, *prev = NULL;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        ListNode* front;
        while (curr) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        ListNode *head1 = head, *head2 = prev;
        while (head1) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};

** Time Complexity :- **
    
Finding the Middle of the Linked List :
The algorithm first counts the number of nodes to find the middle.
This takes O(n) time.
Reversing the Second Half of the List :
The second half of the linked list is reversed in-place.
This takes O(n/2) = O(n) time.
Comparing the Two Halves :
The algorithm then compares the first and reversed second half node by node.
This takes O(n/2) = O(n) time.
Total Time Complexity :
Best Case: O(n) → The list is small or already a palindrome.
Worst Case: O(n) → All three steps (finding the middle, reversing, and comparing) run in O(n).
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Modifications :
The function modifies the linked list in place to reverse the second half.
Only a few pointer variables (temp, curr, prev, front, head1, head2) are used.
Total Space Complexity :
O(1) (Constant Space)
