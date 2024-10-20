class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane's Algoritm
        int currSum = 0; //current sum
        int maxSum = INT_MIN; //maximum sum
        for (int n : nums) {
            currSum = currSum + n;
            maxSum = max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};
