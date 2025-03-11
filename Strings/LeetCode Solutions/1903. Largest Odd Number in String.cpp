** Leetcode Problem 1903 :- **

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

Example 2:
Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".

Example 3:
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.

** Code :- **

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

** Time Complexity :- **
    
Step 1: Iterating Backward Through the String (for loop)
The function iterates from the last character to the first, checking if the digit is odd.
In the worst case, it scans the entire string, which takes O(n) time, where n is the length of num.
Step 2: Extracting the Substring (substr(0, i + 1))
The substr() function runs in O(n) time in the worst case when it returns most of the string.
However, in the best case, where the last digit is already odd, it runs in O(1) time.
Total Time Complexity :
Best Case: O(1) → If the last digit is odd, the loop terminates immediately.
Worst Case: O(n) → If the entire string is even, the loop runs fully.
Overall: O(n) (Linear Time Complexity)

** Space Complexity :- **
    
Step 1: In-Place Processing
The function does not use extra data structures, only a few integer variables (i, num.size()).
Step 2: Substring Storage (substr())
The substring operation creates a new string, which can take up to O(n) space in the worst case.
Total Space Complexity :
O(n) (For Substring Storage in the Worst Case)
