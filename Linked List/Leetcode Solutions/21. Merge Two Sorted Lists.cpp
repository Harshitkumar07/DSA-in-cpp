** Leetcode Problem 21 :- **

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

** Code :- **

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) {
            return list1 ? list1 : list2;
        }
        if (list1->val > list2->val) {
            swap(list1, list2);
        }
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
};

** Time Complexity :- **
    
Recursive Calls: 
In each recursive call, one node from either list1 or list2 is selected, and the recursion progresses to the next node in the selected list.
Since the total number of nodes in both lists combined is n (where n=size of list1+size of list2), the recursion occurs O(n) times.
Work per Recursive Call:
At each recursive call, a comparison is made between the current nodes of list1 and list2, which takes O(1).
Overall Time Complexity: O(n)
The algorithm processes each node exactly once.

** Space Complexity :- **
    
Recursive Stack:
The recursion depth is proportional to the number of nodes in the merged list, which is  O(n).
Auxiliary Storage:
No additional data structures are used; the algorithm modifies the input lists in place.
Overall Space Complexity: O(n)
This is due to the recursive stack used for function calls.
