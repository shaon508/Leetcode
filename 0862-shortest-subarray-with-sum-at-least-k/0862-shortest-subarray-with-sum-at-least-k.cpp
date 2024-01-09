class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long int sum = 0;
        int n = nums.size(), ans = INT_MAX;
        priority_queue<pair<long long int, int>,
                       vector<pair<long long int, int>>,
                       greater<pair<long long int, int>>>
            pq;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum >= k)
                ans = min(ans, i + 1);
            while (!pq.empty() && sum - pq.top().first >= k) {
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};