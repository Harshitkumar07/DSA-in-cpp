** Leetcode Problem 1051 :- **

A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. 
Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).
Return the number of indices where heights[i] != expected[i].

Example 1:
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation: 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.

Example 2: 
Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.

Example 3:
Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.

** Code :- **

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> ans = heights;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != ans[i]) 
                count++;
        }
        return count;
    }
};

** Time Complexity :- **
    
Sorting the Array :
The algorithm first makes a copy of heights and sorts it.
Sorting takes O(n log n) time, where n is the number of elements in heights.
Comparing Elements :
After sorting, the algorithm iterates through the heights array once to count the mismatches.
This takes O(n) time.
Total Time Complexity :
O(n log n) (sorting) + O(n) (comparison) = O(n log n).

** Space Complexity :- **
    
Copying the Array :
The algorithm creates a new vector ans to store the sorted version of heights.
This requires O(n) extra space.
Other Space Usage :
Only a few integer variables (count, loop index) are used, which require O(1) space.
Total Space Complexity :
O(n) (for the sorted array).
