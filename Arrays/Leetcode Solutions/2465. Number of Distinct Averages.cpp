** Leetcode Problem 2465 :- **

You are given a 0-indexed integer array nums of even length.
As long as nums is not empty, you must repetitively:
Find the minimum number in nums and remove it.
Find the maximum number in nums and remove it.
Calculate the average of the two removed numbers.
The average of two numbers a and b is (a + b) / 2.
For example, the average of 2 and 3 is (2 + 3) / 2 = 2.5.
Return the number of distinct averages calculated using the above process.
Note that when there is a tie for a minimum or maximum number, any can be removed.

Example 1:
Input: nums = [4,1,4,0,3,5]
Output: 2
Explanation:
1. Remove 0 and 5, and the average is (0 + 5) / 2 = 2.5. Now, nums = [4,1,4,3].
2. Remove 1 and 4. The average is (1 + 4) / 2 = 2.5, and nums = [4,3].
3. Remove 3 and 4, and the average is (3 + 4) / 2 = 3.5.
Since there are 2 distinct numbers among 2.5, 2.5, and 3.5, we return 2.

Example 2:
Input: nums = [1,100]
Output: 1
Explanation:
There is only one average to be calculated after removing 1 and 100, so we return 1.

** Code :- **

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> ans;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            ans.insert(sum);
            i++;
            j--;
        }
        return ans.size();
    }
};

** Time Complexity :- **
    
    
Step 1: Sorting the Array
The algorithm first sorts the input array nums.
Sorting takes O(n log n) time, where n is the size of the array.

Step 2: Calculating Averages
Two pointers (i from the start and j from the end) are used to traverse the array.
In each iteration, the sum nums[i] + nums[j] is calculated and inserted into a set.
This loop runs n/2 times, and each insertion into a set takes O(log m) time where m is the number of unique sums (at most n/2).
So, the insertion step takes up to O((n/2) * log (n/2)) = O(n log n) in the worst case.

Total Time Complexity :-
Best Case: O(n log n) → Sorting dominates, minimal insertions.
Worst Case: O(n log n) → Sorting + set insertions dominate.
Overall: O(n log n)

** Space Complexity :- **
    
Step 1: Set to Store Distinct Sums
The set ans stores at most n/2 unique integer values.
This results in O(n) space in the worst case.

Step 2: Sorting in Place
The sort() function modifies the array in place and does not require additional memory (unless the underlying implementation uses some auxiliary space).

Total Space Complexity :- 
Best Case: O(1) → Minimal unique pairs. 
Worst Case: O(n) → All pairs have unique sums.
Overall: O(n)
