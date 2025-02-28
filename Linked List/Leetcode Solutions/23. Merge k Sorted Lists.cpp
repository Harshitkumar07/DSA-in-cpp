** Leetcode Problem 23 :- **

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

** Code :- **

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        int n = lists.size();
        while (n > 1) {
            int j = 0;
            for (int i = 0; i < n; i += 2) {
                if (i + 1 < n) {
                    lists[j++] = mergeTwoLists(lists[i], lists[i + 1]);
                } else {
                    lists[j++] = lists[i];
                }
            }
            n = j;
        }
        return lists[0];
    }
};

** Time Complexity :- **
    
Merging Two Lists (mergeTwoLists) :
The mergeTwoLists function is recursive, merging two sorted lists in O(m + n) time, where m and n are the lengths of the two lists.
Merging K Lists (mergeKLists) :
The algorithm merges lists in pairs, reducing the number of lists from k to 1 in log k steps.
Each merging operation takes O(N) time, where N is the total number of nodes across all lists.
The recurrence relation is: T(k)=T(k/2)+O(N)
Solving this recurrence gives O(N log k).
Total Time Complexity :
Best Case: O(N log k) → If lists are already sorted, only merging occurs.
Worst Case: O(N log k) → The entire merging process is executed in full.
Overall: O(N log k) (Optimal for K-way Merging)

** Space Complexity :- **
    
Recursive Stack Space (mergeTwoLists) :
Since mergeTwoLists is recursive, it consumes O(m + n) stack space in the worst case.
However, each call merges smaller lists, leading to O(log k) recursion depth in total.
In-Place Merging (mergeKLists) :
The list merging is done in place, modifying lists[] directly.
Only a few integer variables (n, j, i) are used.
Total Space Complexity :
O(1) (Iterative Merging) + O(N) (Recursive Calls) = O(N) in the worst case
