** Leetcode Problem 206 :- **

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

** Code :- **

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

** Time Complexity :- **
    
Iterating Through the Linked List :
The algorithm traverses the entire linked list using the curr pointer.
Since each node is visited exactly once, the loop runs n times, where n is the number of nodes.
Reversing the Pointer :
For each node, the next pointer is modified to point to the previous node.
This operation is O(1) per node, resulting in a total complexity of O(n).
Total Time Complexity :
As every node is processed only once, the overall time complexity is O(n).

** Space Complexity :- **
    
Constant Extra Space :
The algorithm only uses three pointer variables (prev, curr, next).
No additional data structures or recursive calls are used.
In-Place Modification :
The linked list is reversed in place by updating the next pointers instead of creating a new list.
This ensures that no extra memory is used apart from the given input list.
Total Space Complexity :
Since only O(1) extra space is used, the space complexity remains O(1).
