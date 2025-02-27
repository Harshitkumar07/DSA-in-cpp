** Leetcode Problem 148 :- **

Given the head of a linked list, return the list after sorting it in ascending order. 

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []

** Code :- **

class Solution {
public:
    ListNode* getMid(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left)
            return right;
        if (!right)
            return left;
        ListNode* head;
        if (left->val < right->val) {
            head = left;
            left = left->next;
        } else {
            head = right;
            right = right->next;
        }
        ListNode* curr = head;
        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left)
            curr->next = left;
        if (right)
            curr->next = right;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};

** Time Complexity :- **
    
Step 1: Finding the Middle of the List (getMid)
The slow-fast pointer technique is used to find the middle.
Since it traverses the list once per recursive call, it takes O(n) time.
Step 2: Recursively Sorting the Two Halves (sortList)
The algorithm recursively splits the list into two halves.
This results in O(log n) recursive calls (similar to Merge Sort).
Step 3: Merging the Two Sorted Halves (merge) 
The merge process compares elements from both halves and iterates through all nodes once per level of recursion.
This takes O(n) per recursive level.
Total Time Complexity (Merge Sort Recurrence Relation) :
The recurrence relation follows Merge Sort behavior: T(n)=2T(n/2)+O(n)
Solving this recurrence gives O(n log n).
Final Time Complexity :
Best Case: O(n log n) → The list is already sorted, but still requires splitting and merging.
Worst Case: O(n log n) → The list is in descending order and must be fully sorted.
Overall: O(n log n) (Optimal Sorting Complexity)

** Space Complexity :- **

In-Place Modifications :
The merge operation modifies the linked list in place, so no extra arrays or lists are used.
Recursive Stack Space :
The recursion depth is O(log n) due to repeated splitting.
In the worst case, this contributes O(log n) auxiliary space.
Total Space Complexity :
O(log n) (Recursive Stack Space)
