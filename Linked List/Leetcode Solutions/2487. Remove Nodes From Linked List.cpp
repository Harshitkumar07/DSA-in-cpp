** Leetcode Problem 2487 :- **

You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list. 

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.

** Code :- **

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *prev = NULL, *curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        ListNode* newHead = NULL;
        int maxVal = INT_MIN;
        while (prev) {
            if (prev->val >= maxVal) {
                ListNode* newNode = new ListNode(prev->val);
                newNode->next = newHead;
                newHead = newNode;
                maxVal = prev->val;
            }
            prev = prev->next;
        }
        return newHead;
    }
};

** Time Complexity :- **
    
    
Step 1: Reverse the Linked List :
The first while loop reverses the linked list by iterating through all nodes once.
This takes O(n) time.
Step 2: Process Nodes and Keep Only Maximum Values :
The second while loop iterates through the reversed list and creates a new list containing only nodes that have a value greater than or equal to the maximum seen so far.
This also takes O(n) time.
Total Time Complexity :
Best Case: O(n) → If all nodes are in increasing order, they are kept without extra checks.
Worst Case: O(n) → If all nodes are decreasing, each is checked and included in the new list.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place List Reversal :
The reversal is done in place, using only pointer variables (prev, curr, nextNode), which takes O(1) space.
New List Creation :
The second pass creates a new linked list, which takes O(n) extra space in the worst case (if all nodes are included).
Total Space Complexity :
O(n) (Due to New List Creation)
