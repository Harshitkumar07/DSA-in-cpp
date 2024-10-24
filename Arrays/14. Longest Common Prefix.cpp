class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int k = 0, j = 0;
            while (k < s.size() || j < strs[i].size()) {
                if (s[k] == strs[i][j]) {
                    k++;
                    j++;
                } else {
                    s = strs[i].substr(0, j);
                    break;
                }
            }
        }
        return s;
    }
};
