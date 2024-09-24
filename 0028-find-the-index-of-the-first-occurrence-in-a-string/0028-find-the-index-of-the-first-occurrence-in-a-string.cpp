class Solution {
public:
    int strStr(string s, string t) {
           long long int mod = 1000000007;
    long long int P = 29;
    vector<long long int> v(1009);
    v[0] = 1;
    for (int i = 1; i < 1005; i++) {
        v[i] = (v[i - 1] * P) % mod;
    }

    int n = s.size(), m = t.size(), sHash = 0, tHash = 0;
    if (n < m) return -1;

    for (int i = 0; i < m; i++) {
        tHash = (tHash + (t[i] - 'a' + 1) * v[m - 1 - i]) % mod;
        if(tHash < 0)tHash = (tHash + mod) % mod;
        sHash = (sHash + (s[i] - 'a' + 1) * v[m - 1 - i]) % mod;
        if(sHash < 0)sHash = (sHash + mod) % mod;
    }

    if (tHash == sHash && s.substr(0, m) == t) return 0;

    for (int i = m; i < n; i++) {
        sHash = (sHash - (s[i - m] - 'a' + 1) * v[m - 1]) % mod;
        if(sHash < 0)sHash = (sHash + mod) % mod;
        sHash = (sHash * P + (s[i] - 'a' + 1)) % mod;
        if(sHash < 0)sHash = (sHash + mod) % mod;
        if (sHash == tHash && s.substr(i - m + 1, m) == t) return i - m + 1;
    }

    return -1;
    }
};