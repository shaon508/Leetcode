class Solution {
public:
    int solve(vector<int>& a, int n, int curr, int pre,
              vector<vector<int>>& dp) {
        if (curr == n)
            return 0;
        if (dp[curr][pre + 1] != -1)
            return dp[curr][pre + 1];
        // take
        int take = 0;
        if (pre == -1 || a[pre] < a[curr]) {
            take = 1 + solve(a, n, curr + 1, curr, dp);
        }
        // not take
        int not_take = solve(a, n, curr + 1, pre, dp);
        return dp[curr][pre + 1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(a, n, 0, -1, dp);
    }
};