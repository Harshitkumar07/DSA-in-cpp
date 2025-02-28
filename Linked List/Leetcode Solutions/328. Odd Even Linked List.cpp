** Leetcode Problem 328 :- **

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity. 

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

** Code :- **

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

** Time Complexity :- **
    
Rearranging Nodes into Odd and Even Positions :
The function iterates through the linked list once, processing each node exactly once.
Each node is reassigned to either the odd or even list in O(1) operations.
Total Time Complexity :
Best Case: O(n) → If the list is already ordered correctly, it still processes each node once.
Worst Case: O(n) → The function fully traverses the list.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Modifications :
The function reorders the linked list in place, meaning it does not use extra memory.
Only a few pointer variables (odd, even, evenHead) are used.
Total Space Complexity :
O(1) (Constant Space)
