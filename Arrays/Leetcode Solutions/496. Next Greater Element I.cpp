** Leetcode Problem 496 :- **

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

** Code :- **

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (s.size() > 0 && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Processing nums2 Using a Monotonic Stack
The algorithm iterates once through nums2 (size M) in reverse order.
Each element is pushed onto the stack once and popped at most once.
The while loop pops elements from the stack when encountering a larger element.
Since each element is pushed and popped at most once, the total stack operations are O(M).
Step 2: Mapping Elements from nums1
The algorithm iterates through nums1 (size N) and retrieves values from the hash map m in O(1) time per element.
This step takes O(N) time.

Total Time Complexity :
Best Case: O(M + N) → If nums2 is strictly decreasing, each element is pushed only once.
Worst Case: O(M + N) → If nums2 is strictly increasing, each element is pushed and popped once.
Overall: O(M + N) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: Storage for Stack and Hash Map
The stack stores elements from nums2. In the worst case (strictly increasing sequence), it holds M elements, requiring O(M) space.
The unordered_map m stores the next greater element for up to M elements, using O(M) space.
The output vector ans stores N elements, using O(N) space.

Total Space Complexity :
Best Case: O(M + N) → If nums2 has repeating elements, fewer elements may be stored in m or s.
Worst Case: O(M + N) → If nums2 is strictly increasing, the stack holds all elements.
Overall: O(M + N) (Linear Space Complexity)
