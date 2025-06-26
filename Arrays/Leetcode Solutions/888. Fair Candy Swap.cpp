** Leetcode Problem 888 :- **

Alice and Bob have a different total number of candies. You are given two integer arrays aliceSizes and bobSizes where aliceSizes[i] is the number of candies of the ith box of candy that Alice has and bobSizes[j] is the number of candies of the jth box of candy that Bob has.
Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the same total amount of candy. The total amount of candy a person has is the sum of the number of candies in each box they have.
Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, and answer[1] is the number of candies in the box that Bob must exchange. If there are multiple answers, you may return any one of them. 
It is guaranteed that at least one answer exists. 

Example 1:
Input: aliceSizes = [1,1], bobSizes = [2,2]
Output: [1,2]

Example 2:
Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]

Example 3:
Input: aliceSizes = [2], bobSizes = [1,3]
Output: [2,3]

** Code :- **

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;
        for (int a : aliceSizes) {
            sumA += a;
        }
        for (int b : bobSizes) {
            sumB += b;
        }
        int diff = (sumB - sumA) / 2;
        unordered_set<int> set(bobSizes.begin(), bobSizes.end());
        for (int a : aliceSizes) {
            if (set.count(a + diff)) {
                return {a, a + diff};
            }
        }
        return {};
    }
};

** Time Complexity :- **
    
Step 1: Calculating Total Sums
The algorithm first computes the total sum of aliceSizes and bobSizes.
Each vector is traversed once to compute the respective sums.
Let N be the size of aliceSizes, and M be the size of bobSizes.
Calculating sumA: O(N)
Calculating sumB: O(M)

Step 2: Constructing the Hash Set
An unordered_set is created from bobSizes, which takes O(M) time.

Step 3: Searching for a Valid Pair
For each candy size a in aliceSizes, the algorithm checks whether a + diff exists in the set.
Each lookup in the set takes average-case O(1), and this is done for N elements.

Total Time Complexity :-
    
Best Case: O(N + M) → Valid pair found early.
Worst Case: O(N + M) → All elements processed.
Overall: O(N + M) (Linear Time Complexity)

** Space Complexity :- **
    
The algorithm uses:
A hash set (unordered_set) to store all elements from bobSizes → O(M)
A few integer variables for sums and difference calculations.

Total Space Complexity :-

Best Case: O(M)
Worst Case: O(M)
Overall: O(M) (Linear Space Complexity with respect to bobSizes)
