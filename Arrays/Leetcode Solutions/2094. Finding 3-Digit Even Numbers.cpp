** Leetcode Problem 2094 :- **

You are given an integer array digits, where each element is a digit. The array may contain duplicates.
You need to find all the unique integers that follow the given requirements:
The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
Return a sorted array of the unique integers.

Example 1:
Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.

Example 2:
Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882. 

Example 3:
Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.

** Code :- **

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0)
                continue;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0) {
                        ans.insert(num);
                    }
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};

** Time Complexity :- **
Step 1: Iterating Through All Unique Combinations of 3 Digits
We use three nested loops (i, j, k) to generate all possible 3-digit numbers.
Each loop runs n times, so the total iterations are O(n³).

Inside the innermost loop:
A number is formed: digits[i] * 100 + digits[j] * 10 + digits[k] → O(1)
Checked whether it is even (% 2 == 0) → O(1)
If even, inserted into a set → O(log m), where m is the number of unique valid even 3-digit numbers.
Since the maximum number of unique 3-digit combinations from digits [0-9] is limited (at most a few hundred), we treat set insertion as O(1) for practical analysis.

Total Time Complexity :-
O(n³) — Cubic time due to three nested loops.

** Space Complexity :- **
    
Step 1: Storing Valid Numbers
A set<int> is used to store unique 3-digit even numbers.
In the worst case (digits of length 10, all unique), you can form a limited number of 3-digit even numbers, so the set will store at most a few hundred values → O(1) (constant in practical terms).
Finally, converting the set to a vector: vector<int>(ans.begin(), ans.end()) → linear in number of valid numbers stored.

Total Space Complexity :-
O(1) — since the maximum size of the result is bounded and not dependent on input size n.
