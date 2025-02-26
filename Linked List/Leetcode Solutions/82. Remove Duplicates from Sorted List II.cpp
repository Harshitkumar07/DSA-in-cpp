** Leetcode Problem 82 :- **

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well. 

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]

** Code :- **

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *curr = head, *prev = NULL;
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                if (prev) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};

** Time Complexity :- **
    
Traversing the Linked List :
The algorithm iterates through the linked list once, processing each node at most once.
In the worst case, it checks every node O(n) times.
Skipping Duplicates :
When encountering duplicate nodes, the function skips over them using a nested while loop.
However, every node is still visited at most once, making the worst-case complexity O(n).
Total Time Complexity :
Best Case: O(n) → If there are no duplicates, each node is processed once.
Worst Case: O(n) → If all elements are duplicates, nodes are skipped but still visited once.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
In-Place Modification :
The function modifies the linked list in place, requiring only a few pointer variables (curr, prev).
No extra data structures or recursion are used.
Total Space Complexity :
O(1) (Constant Space)
