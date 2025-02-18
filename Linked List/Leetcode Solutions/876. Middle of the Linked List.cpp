** Leetcode Problem 876 :- **

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

** Code :- **

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

** Time Complexity :- **
    
Traversal Using Two Pointers :
The algorithm uses two pointers (slow and fast) to traverse the linked list.
fast moves twice as fast as slow, meaning that by the time fast reaches the end, slow will be at the middle.
This requires only one pass through the list.
Total Time Complexity :
Since we traverse O(n) nodes in a single loop, the time complexity is O(n), where n is the number of nodes in the linked list.

** Space Complexity :- **
    
Constant Extra Space :
The algorithm only uses a few pointer variables (slow and fast).
No additional data structures are used.
Total Space Complexity :
Since only O(1) extra space is used, the space complexity is O(1).
