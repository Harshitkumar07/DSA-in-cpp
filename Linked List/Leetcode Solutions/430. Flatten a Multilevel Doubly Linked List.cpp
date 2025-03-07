** Leetcode Problem 430 :- **

You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. 
These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.
Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. 
The nodes in the child list should appear after curr and before curr.next in the flattened list.
Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null. 

Example 1:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 2:
Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 3:
Input: head = []
Output: []
Explanation: There could be empty list in the input.

** Code :- **

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
            return head;
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                // flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;

                // find tail
                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                // attach the tail with next ptr
                if (next != nullptr) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

** Time Complexity :- **
    
Step 1: Traversing the Multilevel Doubly Linked List
The algorithm iterates through each node once, and if a node has a child, it recursively flattens the child list.
In the worst case, every node has a child, meaning each node is visited twice (once before flattening, once after).
This results in O(n) + O(n) = O(n) operations.
Step 2: Finding the Tail
After flattening a child list, the algorithm traverses the child list again to find the tail.
This takes O(m) time, where m is the length of the child list.
Since each node is processed once in the main list and once in a child list, the total complexity remains O(n).
Total Time Complexity :
Best Case: O(n) → If no node has a child, the list is traversed once.
Worst Case: O(n) → If every node has a child, they are all processed twice.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Recursive Call Stack Usage :
The function uses recursion to flatten child lists.
In the worst case, if the list is deeply nested, the recursive call stack reaches O(d), where d is the depth of the deepest child list.
In the best case (if the list is already flat), the space complexity is O(1).
Total Space Complexity :
Best Case: O(1) → If there are no child nodes, no extra space is used.
Worst Case: O(d) → If the list is deeply nested, recursion depth reaches d.
Overall: O(d) (Recursive Stack Space)
