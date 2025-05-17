** Leetcode Problem 1550 :- **

Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

Example 1:
Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.

Example 2:
Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.

** Code :- **

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int num : arr) {
            if (num % 2 != 0) {
                count++;
                if (count == 3) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
        return false;
    }
};

** Time Complexity :- **
    
Step 1: Iterating Through the Array
The function loops through the arr once using a range-based for loop.

For each element:
Checks if the number is odd using num % 2 != 0 → constant time operation.
If odd, increments a counter and checks if it reaches 3.
If even, resets the counter to 0.
Each operation inside the loop takes constant time.

Total Time Complexity :-
O(n), where n is the size of the array.

** Space Complexity :- **
    
Step 1: Variables Used
Only a single integer variable count is used to track consecutive odd numbers.
No additional data structures or memory allocation.

Total Space Complexity :-
O(1) — Constant space.
