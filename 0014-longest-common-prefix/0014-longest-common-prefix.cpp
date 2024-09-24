class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int mn = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < mn) {
                mn = strs[i].size();
            }
        }
        bool ok = true;
        for (int i = 0; i < mn && ok; i++) {
            for (int j = 0; j < strs.size() && ok; j++) {
                if (strs[j][i] != strs[0][i]) {
                    ok = false;
                }
            }
            if (ok)
                ans.push_back(strs[0][i]);
        }
        return ans;
    }
};