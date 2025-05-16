** Leetcode Problem 2918 :- **

You are given two arrays nums1 and nums2 consisting of positive integers.
You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.
Return the minimum equal sum you can obtain, or -1 if it is impossible.

Example 1:
Input: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
Output: 12
Explanation: We can replace 0's in the following way:
- Replace the two 0's in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
- Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.

Example 2:
Input: nums1 = [2,0,2,0], nums2 = [1,4]
Output: -1
Explanation: It is impossible to make the sum of both arrays equal.

** Code :- **

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        bool hasZero1 = false, hasZero2 = false;
        for (int num : nums1) {
            if (num == 0) {
                sum1++;
                hasZero1 = true;
            } else {
                sum1 += num;
            }
        }
        for (int num : nums2) {
            if (num == 0) {
                sum2++;
                hasZero2 = true;
            } else {
                sum2 += num;
            }
        }
        if (sum1 == sum2) 
            return sum1;
        if (sum1 > sum2 && hasZero2) 
            return sum1;
        if (sum2 > sum1 && hasZero1) 
            return sum2;
        return -1;
    }
};

** Time Complexity :- **

Step 1: Iterating Over nums1
The function iterates through the nums1 array once.

For each element:
If it is 0, it increments sum1 by 1 and sets hasZero1 to true.
Otherwise, it adds the number to sum1.
This takes O(n) time, where n is the size of nums1.

Step 2: Iterating Over nums2
Similarly, the function iterates through the nums2 array once.
Performs the same kind of operations as above.
This takes O(m) time, where m is the size of nums2.

Step 3: Comparisons and Return Logic
A few constant-time comparisons are made to determine the return value.

Total Time Complexity :-
O(n + m), where n is the length of nums1 and m is the length of nums2.

** Space Complexity :- **
    
Step 1: Variables Used
A few scalar variables: sum1, sum2, hasZero1, hasZero2.
No extra space is used proportional to input size.

Total Space Complexity :-
O(1) — Constant space.
