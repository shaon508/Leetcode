class Solution {
private:
    void solve(vector<int> v, int ind, vector<int> o,
               vector<vector<int>>& ans) {
        if (ind >= v.size()) {
            ans.push_back(o);
            return;
        }
        // exclude
        solve(v, ind + 1, o, ans);
        // include
        o.push_back(v[ind]);
        solve(v, ind+1, o, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> o;
        int ind = 0;
        solve(nums, ind, o, ans);
        return ans;
    }
};