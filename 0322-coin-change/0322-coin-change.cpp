class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<long long int> dp(amount + 1);
        for (int i = 1; i <= amount; i++) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            dp[amount] = -1;
        return dp[amount];
    }
};