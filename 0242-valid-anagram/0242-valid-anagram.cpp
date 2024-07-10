class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(27, 0), b(27, 0);
        int n = s.size(), m = t.size();
        for (int i = 0; i < n; i++)
            a[(s[i] - 'a')]++;
        for (int i = 0; i < m; i++)
            b[(t[i] - 'a')]++;
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i])
                return false;

        return true;
    }
};