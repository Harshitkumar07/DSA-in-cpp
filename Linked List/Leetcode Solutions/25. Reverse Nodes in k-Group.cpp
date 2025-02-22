** Leetcode Problem 25 :- **

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed. 

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

** Code :- **

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr != NULL && count < k) {
            curr = curr->next;
            count++;
        }
        if (count == k) {
            ListNode* next = NULL;
            ListNode* prev = NULL;
            curr = head;
            count = 0;
            while (curr != NULL && count < k) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            head->next = reverseKGroup(curr, k);
            return prev;
        }
        return head;
    }
};

** Time Complexity :- **
    
Counting k Nodes in Each Group :
The algorithm first checks if there are at least k nodes in the current segment.
This requires O(k) time.
Reversing k Nodes :
If there are k nodes, they are reversed one by one using a standard in-place reversal.
Reversing k nodes takes O(k) time.
Recursive Call for Remaining Nodes :
After reversing a group, the function is recursively called on the remaining part of the list.
Since we divide the list into groups of k, the number of recursive calls is O(n/k).
Total Time Complexity :
Each recursive call processes k nodes in O(k) time.
There are O(n/k) recursive calls.
So the total time complexity is: O(k)×O(n/k)=O(n)
Best Case: O(n) → If k = 1, no reversal happens, and we traverse the list once.
Worst Case: O(n) → If k is a factor of n, we fully reverse each group.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Recursive Calls :
Each recursive call stores function call stack frames.
In the worst case, there are O(n/k) recursive calls, leading to O(n/k) space usage.
In-Place Reversal :
Apart from recursion, the function modifies the linked list in place using a few pointer variables (curr, next, prev).
This requires O(1) extra space.
Total Space Complexity :
O(n/k) (Recursive Stack Space)
