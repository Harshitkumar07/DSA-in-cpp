** Leetcode Problem 2 :- **

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. 

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

** Code :- **

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;
        while ((l1 != NULL || l2 != NULL) || carry) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through Both Linked Lists
The algorithm traverses both linked lists once, digit by digit, performing addition.
Since each list has at most O(max(m, n)) nodes (where m and n are the lengths of l1 and l2), the loop runs O(max(m, n)) times.
Step 2: Creating New Nodes for the Result List
For each digit sum, a new node is created in O(1) time.
Since at most O(max(m, n)) nodes are created, this part also takes O(max(m, n)) time.
Total Time Complexity :
Best Case: O(max(m, n)) → If both numbers are of similar length.
Worst Case: O(max(m, n)) → If one number is significantly longer, we still process every node.
Overall: O(max(m, n)) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: New Linked List Storage
A new linked list is created to store the result.
In the worst case, if there is a carry in the final sum, the list will have max(m, n) + 1 nodes.
This takes O(max(m, n)) space.
Step 2: Auxiliary Variables
Only a few integer and pointer variables (dummy, temp, carry, sum) are used, which require O(1) space.
Total Space Complexity :
O(max(m, n)) (For New List Storage)
