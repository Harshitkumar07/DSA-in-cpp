** Leetcode Problem 2698 :- **

Given a positive integer n, return the punishment number of n.
The punishment number of n is defined as the sum of the squares of all integers i such that:
1 <= i <= n
The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.

Example 1:
Input: n = 10
Output: 182
Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
Hence, the punishment number of 10 is 1 + 81 + 100 = 182

Example 2:
Input: n = 37
Output: 1478
Explanation: There are exactly 4 integers i in the range [1, 37] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1. 
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
- 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478

** Code :- **

class Solution {
public:
    bool canPartition(const string& s, int target, int idx = 0,
                      int currSum = 0) {
        if (idx == s.length()) {
            return currSum == target;
        }
        int num = 0;
        for (int i = idx; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0');
            if (canPartition(s, target, i + 1, currSum + num)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (canPartition(to_string(square), i)) {
                ans += square;
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Checking Each Number from 1 to n :
The outer loop runs from 1 to n, meaning it executes O(n) iterations.
For each i, we calculate i² in O(1) time.
Recursive Partitioning (canPartition Function) :
The recursion explores all ways to partition the string representation of i² into numbers.
For a number with d digits, there are O(2^d) ways to partition it.
Since i² can have up to O(log n) digits, the recursion runs in O(2^(log n)) time.
Total Time Complexity :
The worst case involves checking n numbers, each requiring O(2^(log n)) recursive calls.
This results in an approximate O(n * 2^(log n)) time complexity.
Since 2^(log n) ≈ n, the final complexity is O(n²) in the worst case.

** Space Complexity :- **

Recursive Stack Depth :
The recursion depth is at most O(log n) since the largest number processed is n², which has O(log n) digits.
Total Space Complexity :
Best Case: O(1) → If partitions are found early, recursion does not go deep.
Worst Case: O(log n) → If the recursion explores all partitions, it uses O(log n) stack space.
