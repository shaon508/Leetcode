class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int sum = 0, ans = 0;
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == k)
                ans++;
            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};