** Leetcode Problem 239 :- **

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]

** Code :- **

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        // First window
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // swm
        for (int i = k; i < nums.size(); i++) {
            ans.push_back(nums[dq.front()]);
            // remove ele not part of curr window
            while (dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }
            // remove smaller values
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Processing the First Window
The first loop runs for the first k elements.
Each element is added to the deque, and elements smaller than nums[i] are removed.
Since each element is pushed and popped at most once, this loop runs in O(k) time.

Step 2: Sliding the Window Across the Array
The second loop runs for the remaining N - k elements.

Each element is:
Compared and pushed into the deque.
Any elements that fall out of the window (dq.front() <= i - k) are removed.
Any smaller elements (nums[dq.back()] <= nums[i]) are removed.
Since each element is pushed and popped at most once from the deque, this loop runs in O(N - k) time.

Total Time Complexity :-
Best Case: O(N) → Each element is inserted and removed once.
Worst Case: O(N) → The deque operations ensure each element is processed only once.
Overall: O(N) (Linear Time Complexity).

** Space Complexity :- **
    
Step 1: Storage for Deque
The deque stores indices of at most k elements.
Worst case: O(k) space, as it never holds more than k elements.

Step 2: Storage for Output Vector
The result array stores N - k + 1 values.
In the worst case, it takes O(N) space.

Total Space Complexity :-
Best Case: O(k) → When storing minimal values.
Worst Case: O(N) (for output storage).
Overall: O(N) (Linear Space Complexity due to output storage).
