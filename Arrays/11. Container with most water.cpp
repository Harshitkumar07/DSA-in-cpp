class Solution {
public:
    int maxArea(vector<int>& height) {
        //Two pointer solutions
        int lp = 0; //left pointer
        int rp = height.size() - 1; //right pointer
        int maxWater = 0;
        while (lp < rp) {
            int water = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currWater = water * ht;
            maxWater = max(maxWater, currWater);
            //Ternary operator
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};
