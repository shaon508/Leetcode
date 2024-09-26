class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, c = 0, left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vowel(s[i]))
                c++;
            if (i - left >= k) {
                if (vowel(s[left]))
                    c--;
                left++;
            }
            ans = max(ans, c);
        }
        return ans;
    }
    bool vowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
};