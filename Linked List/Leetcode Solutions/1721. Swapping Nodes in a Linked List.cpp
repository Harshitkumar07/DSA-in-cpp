** Leetcode Problem 1721 :- **

You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed). 

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

** Code :- **

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        ListNode *first = head, *second = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }
        for (int i = 1; i < len - k + 1; i++) {
            second = second->next;
        }
        swap(first->val, second->val);
        return head;
    }
};

** Time Complexity :- **
    
Step 1: Finding the Length of the Linked List
The algorithm first traverses the entire linked list to determine its length N.
This requires a single pass through the list.
Time Complexity: O(N) (since we visit each node once).

Step 2: Finding the k-th and (N-k+1)-th Nodes
After determining the length, the algorithm performs two separate traversals:
One to locate the k-th node from the beginning.
Another to locate the k-th node from the end (N-k+1).
Each of these traversals takes O(k) + O(N-k) = O(N) in the worst case.
Step 3: Swapping the Node Values
Swapping two integer values takes O(1) time, as it's a simple assignment operation.

Total Time Complexity :-
Best Case: O(N) → If k is near the start or end, but we still need two traversals.
Worst Case: O(N) → If k is in the middle, still requiring two full traversals.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Pointer Storage
The algorithm uses only a few extra pointers (curr, first, second).
These pointers are used for traversal and swapping but do not scale with input size.

Step 2: No Extra Data Structures
The algorithm operates directly on the linked list and does not use extra arrays or stacks.
Only a fixed number of variables are used.

Total Space Complexity :-
Best Case: O(1) → No additional data structures beyond a few pointers.
Worst Case: O(1) → Even in the worst case, only a constant amount of space is used.
Overall: O(1) (Constant Space Complexity)
