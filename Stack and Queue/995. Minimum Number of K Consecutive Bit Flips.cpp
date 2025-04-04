** Leetcode Problem 995 :- **

You are given a binary array nums and an integer k.
A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [0,1,0], k = 1
Output: 2
Explanation: Flip nums[0], then flip nums[2].

Example 2:
Input: nums = [1,1,0], k = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].

Example 3:
Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3
Explanation: 
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]

** Code :- **

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int flip = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!q.empty() && q.front() < i) {
                q.pop();
            }
            if (q.size() % 2 == nums[i]) {
                if (i + k - 1 >= n) {
                    return -1;
                }
                q.push(i + k - 1);
                flip++;
            }
        }
        return flip;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the Array
The loop runs for all N elements.
For each index i, we:
Check if the queue front is out of range (O(1) operation).
Determine if a flip is needed based on the queue size (O(1) operation).
Push a new index into the queue if a flip occurs (O(1) operation).
Total time for traversal: O(N).

Step 2: Handling the Queue
The queue stores at most O(K) elements at any point.
Each index is pushed and popped at most once.
Queue operations (push, pop, front) take O(1) time.

Total Time Complexity :-
Best Case: O(N) → If minimal flips are needed.
Worst Case: O(N) → If every element requires a flip.
Overall: O(N) (Linear Time Complexity).

** Space Complexity :- **
    
Step 1: Queue Storage
The queue stores at most K elements at a time.
Worst case: O(K) space when flips are frequent.

Step 2: Extra Variables
We use a few integer variables (flip, n).
Total space for extra variables: O(1).

Total Space Complexity :-
Best Case: O(1) → If no flips are needed.
Worst Case: O(K) → If many flips are needed.
Overall: O(K) (Linear Space Complexity in Terms of Flip Window).
