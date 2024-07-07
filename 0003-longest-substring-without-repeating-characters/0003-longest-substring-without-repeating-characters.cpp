class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0, ans = 0;
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            if (!mp[s[i]]) {
                ans = max(ans, i - left + 1);

            } else {
                while (mp[s[i]]) {
                    mp[s[left]]--;
                    left++;
                }
            }
            mp[s[i]]++;
        }
        return ans;
    }
};