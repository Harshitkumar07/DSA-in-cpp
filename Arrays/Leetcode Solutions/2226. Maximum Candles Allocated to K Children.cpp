** Leetcode Problem 2226 :- **

You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.
You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.
Return the maximum number of candies each child can get.

Example 1:
Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.

Example 2:
Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.

** Code :- **

class Solution {
public:
    bool canAllocateCandies(const vector<int>& candies, long long k,
                            int target) {
        long long count = 0;
        for (int num : candies) {
            count += num / target;
            if (count >= k)
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = 0;
        for (int num : candies) {
            if (num > high) {
                high = num;
            }
        }
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAllocateCandies(candies, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Finding the Maximum Candy Count
The algorithm first determines the maximum number of candies in candies by iterating through the array.
This takes O(N) time, where N is the size of the candies array.
Step 2: Binary Search on the Maximum Candy Count
The algorithm uses binary search to find the maximum possible candy distribution.
The search space ranges from 1 to max(candies) (denoted as M).
The number of iterations in binary search is O(log M).
Step 3: Checking if a Certain Candy Count is Feasible
In each binary search step, the algorithm checks whether it's possible to allocate at least k candies per child.
This check iterates over candies in O(N) time.

Total Time Complexity :
Best Case: O(N) → If binary search stops early.
Worst Case: O(N log M) → If binary search runs for log M steps, performing an O(N) feasibility check at each step.
Overall: O(N log M) (Logarithmic-Binary Search Complexity)

** Space Complexity :- **
    
Step 1: Storage for Variables
The algorithm uses a few integer variables (low, high, mid, ans) and a function for feasibility checking.
No additional space is used apart from the input array.

Total Space Complexity :
Best Case: O(1) → No additional storage is required apart from variables.
Worst Case: O(1) → The same applies regardless of input size.
Overall: O(1) (Constant Space Complexity)
