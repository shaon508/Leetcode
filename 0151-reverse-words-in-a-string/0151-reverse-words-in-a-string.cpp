class Solution {
public:
    string reverseWords(string s) {
        int True = 0;
        string ans = "", temp = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (i == 0 && s[i]!=' ') {
                temp.push_back(s[i]);
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                temp.clear();
            } else if (s[i]!=' ') {
                temp.push_back(s[i]);
                True = 1;
            } else if (True && s[i] == ' ') {
                reverse(temp.begin(), temp.end());
                ans = ans + temp + ' ';
                temp.clear();
                True = 0;
            }
        }
        if (ans[ans.size() - 1] == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};