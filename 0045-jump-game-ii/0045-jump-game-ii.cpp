class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size(), ans = 0, Max = 0;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n && j <= i + arr[i]; j++) {
                if (dp[j] > dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
        return dp[n - 1];
    }
};