class Solution {
public:
    int len1, len2, len3;
    int memo[101][101][201];
    bool check(string s1, string s2, string s3, int i, int j, int k) {
        if (i >= len1 && j >= len2 && k >= len3)
            return true;
        if (k >= len3)
            return false;
        if (memo[i][j][k] != -1)
            return memo[i][j][k];
        return memo[i][j][k] =
                   (((s1[i] == s3[k]) && check(s1, s2, s3, i + 1, j, k + 1)) ||
                    ((s2[j] == s3[k]) && check(s1, s2, s3, i, j + 1, k + 1)));
    }
    bool isInterleave(string s1, string s2, string s3) {
        len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        memset(memo, -1, sizeof(memo));
        return check(s1, s2, s3, 0, 0, 0);
    }
};