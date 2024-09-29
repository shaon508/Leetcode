class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mpS, mpT;
        int left = 0, right = 0, min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < t.size(); i++) {
            mpT[t[i]]++;
        }
        mpS[s[right]]++;
        while (right < s.size()) {
            bool flag = true;
            for (auto it : mpT) {
                if (mpS[it.first] < it.second) {
                    flag = false;
                }
            }
            if (flag) {
                int len = right - left + 1;
                if (len < min) {
                    min = len;
                    a = left;
                    b = right;
                }
                mpS[s[left]]--;
                left++;
            } else {
                right++;
                mpS[s[right]]++;
            }
        }
        string ans = "";
        if (a != -1) {
            for (int i = a; i <= b; i++) {
                ans += s[i];
            }
        }
        return ans;
    }
};