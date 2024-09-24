class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1)
            return false;
        for (int i = 0; i + i < s.size(); i++) {
            if (s.size() % (i + 1) == 0) {
                bool ok = true;
                for (int j = i + 1; j < s.size() && ok; j++) {
                    if (s[j] != s[j % (i + 1)]) {
                        ok = false;
                    }
                }
                if (ok)
                    return true;
            }
        }
        return false;
    }
};