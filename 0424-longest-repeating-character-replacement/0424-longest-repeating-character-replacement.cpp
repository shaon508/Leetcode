class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> freq;
        int ans = 0, maxFreq = 0, change = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            freq[s[right]]++;
            maxFreq = 0;
            for (char i = 'A'; i <= 'Z'; i++) {
                maxFreq = max(maxFreq, freq[i]);
            }
            change = right - left + 1 - maxFreq;

            if (change <= k) {
                ans = max(ans, right - left + 1);
                right++;
            } else {
                freq[s[left]]--;
                left++;
                right++;
            }
        }
        return ans;
    }
};
