class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                t += s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z')
                t += (s[i] - 'A' + 'a');
            else if (s[i] >= '0' && s[i] <= '9')
                t += s[i];
        }
        bool ans = true;
        int i = 0, j = t.size() - 1;
        while (i < j) {
            if (t[i] != t[j])
                ans = false;
            i++, j--;
        }
        return ans;
    }
};