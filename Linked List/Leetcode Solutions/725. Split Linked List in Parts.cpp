** Leetcode Problem 725 :- **

Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
Return an array of the k parts. 

Example 1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

** Code :- **

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        int part = len / k, rem = len % k;
        vector<ListNode*> ans(k, nullptr);
        ListNode* curr = head;
        for (int i = 0; i < k && curr; i++) {
            ans[i] = curr;
            int currPart = part + (i < rem ? 1 : 0);
            for (int j = 0; j < currPart - 1; j++) {
                curr = curr->next;
            }
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Calculating the Length of the Linked List
The algorithm first traverses the entire linked list to compute its length.
It uses a single pointer temp to move through the list, incrementing a counter.
This takes O(N) time, where N is the total number of nodes in the linked list.

Step 2: Dividing the List into k Parts
The list is split into k parts, and the size of each part is either len / k or len / k + 1 (to distribute remaining nodes).
A loop runs k times to assign the heads of each part.
Inside this loop, for each part, a sub-loop runs up to currPart - 1 times to traverse that segment.
Across all k parts, the number of node visits is still N, as each node is visited exactly once while splitting.

Total Time Complexity :-
Best Case: O(N) → Every node is visited once to compute the length and once more to split.
Worst Case: O(N) → Same as best case, since list traversal dominates.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Output Vector
A vector of size k is created to hold the head of each part.
This contributes O(k) space.

Step 2: Extra Variables and Pointers
Pointers such as curr, temp, and integer counters len, part, rem use constant space.
No additional dynamic data structures are used apart from the result vector.

Total Space Complexity :-
Best Case: O(k) → Only the output vector occupies space.
Worst Case: O(k) → Still O(k), regardless of how the list is split.
Overall: O(k) (Linear Space Complexity in Terms of Output Size)
