** Leetcode Problem 769 :- **

You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.

Example 1:
Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.

Example 2:
Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.

** Code :- **

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, maxSoFar = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) {
                chunks++;
            }
        }
        return chunks;
    }
};

** Time Complexity :- **
    
Step 1: Single Pass Through the Array
The algorithm iterates through the input vector arr from index 0 to n - 1.
For each index i, it updates maxSoFar to be the maximum of itself and arr[i].
If maxSoFar == i, it increases the chunks counter.
Each element is visited exactly once.
Let N be the size of the vector arr.
All operations inside the loop are constant time.

Total Time Complexity :-
Best Case: O(N) → Perfectly sorted or easily chunkable.
Worst Case: O(N) → Entire array needs to be checked.
Overall: O(N) (Linear Time Complexity)

** Space Complexity :- **
    
The algorithm uses a few integer variables: chunks, maxSoFar, and loop index i.
No additional data structures are created.

Total Space Complexity :-
Best Case: O(1)
Worst Case: O(1)
Overall: O(1) (Constant Space Complexity)
