class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        string ans;
        int left, right, maxx = 0, c = 0;
        for (int i = 0; i < length; i++) {
            // for odd palindrome
            left = i, right = i;
            while (left >= 0 && right < length && s[left] == s[right]) {
                left--;
                right++;
            }
            c = right - left - 1;
            if (c > maxx) {
                maxx = c;
                ans = "";
                for (int j = left + 1; j < right; j++) {
                    ans.push_back(s[j]);
                }
            }
            // even palindrome
            left = i, right = i + 1;
            while (left >= 0 && right < length && s[left] == s[right]) {
                left--;
                right++;
            }
            c = right - left - 1;
            if (c > maxx) {
                maxx = c;
                ans = "";
                for (int j = left + 1; j < right; j++) {
                    ans.push_back(s[j]);
                }
            }
        }
        return ans;
    }
};