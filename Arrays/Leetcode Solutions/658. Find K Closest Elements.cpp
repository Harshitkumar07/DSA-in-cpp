** Leetcode Problem 658 :- **

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,1,2,3,4,5], k = 4, x = -1
Output: [1,1,2,3]

** Code :- **

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < x) 
                left = mid + 1;
            else 
                right = mid;
        }
        left = right - 1;
        right = right;
        vector<int> ans;
        while (k-- > 0) {
            if (left < 0) {
                ans.push_back(arr[right++]);
            } else if (right >= n) {
                ans.push_back(arr[left--]);
            } else if (x - arr[left] <= arr[right] - x) {
                ans.push_back(arr[left--]);
            } else {
                ans.push_back(arr[right++]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

** Time Complexity :- **
    
Step 1: Binary Search to Find Closest Position
The algorithm first performs a binary search to find the closest element to x in arr.
This takes O(log n) time.
Step 2: Expanding the Window to Find k Closest Elements
The algorithm uses a two-pointer technique (left and right) to expand outward and select k closest elements.
This takes O(k) time.
Step 3: Sorting the Selected Elements
The selected k elements are sorted before returning.
Sorting k elements takes O(k log k) time.
Total Time Complexity :
Best Case: O(log n + k) → If the k elements are already sorted.
Worst Case: O(log n + k log k) → Sorting is the most expensive operation when k is large.
Overall: O(log n + k log k) (Efficient for Large n and Small k)

** Space Complexity :- **
    
In-Place Computation :    
The function stores only k elements in ans, so it requires O(k) extra space.
Sorting modifies ans, but does not require extra space beyond O(k).
Total Space Complexity :
O(k) (Storage for k Closest Elements)
