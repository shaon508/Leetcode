class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0, c = 0, st =INT_MIN;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }
        for (auto it : mp) {
            if (st == INT_MIN) {
                c = 1;
                st = it.first;
            }
            if ((it.first - st) == 1) {
                c++;
                st = it.first;
                ans = max(ans, c);
            } else {
                c = 1;
                st = it.first;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};