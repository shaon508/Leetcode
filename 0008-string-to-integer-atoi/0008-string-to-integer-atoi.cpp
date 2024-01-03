class Solution {
public:
    int myAtoi(string s) {
   int minus = 0, plus = 0, i = 0, a, bound = 0, n = s.size(),ans;
        long long int num = 0, sign = 1;
        while (i < n &&( (s[i] == ' '&& minus+plus==0)|| s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                minus++;
                sign = -1;
            }
            if (s[i] == '+') {
                plus++;
                sign = 1;
            }
            i++;
        }
        if (plus + minus > 1)
            ans= 0;
        else {
            while (i < n && (s[i] >= '0' && s[i] <= '9') && !bound) {
                a = s[i] - '0';
                num = num * 10LL + a;
                if (num > INT_MAX) {
                    num = INT_MAX;
                    bound = 1;
                }
                i++;
            }
            if (minus == 1 && bound)
                ans= INT_MIN;
            else
                ans= sign * num;
        }
        return ans;
    }
};