class Solution {
public:
    long long powMod(long long base, long long power, long long mod) {
        if (power == 0)
            return 1LL;
        long long temp = powMod(base, power / 2, mod);
        if (power % 2) {
            return (((base * temp) % mod) * temp) % mod;
        } else {
            return (temp * temp) % mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long mod = (long long)1e9 + 7;
        long long ans = powMod(5LL, (n + 1) / 2, mod);
        ans %= mod;
        ans *= powMod(4LL, n / 2, mod);
        ans %= mod;
        return (int)ans;
    }
};