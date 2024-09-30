class Solution {
public:
    bool validPalindrome(string s) { return solve(s, 0, s.size() - 1, 0); }

private:
    bool solve(const string s, int left, int right, int cnt) {
        if (cnt > 1) {
            return false;
        }
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return solve(s, left + 1, right, cnt + 1) ||
                       solve(s, left, right - 1, cnt + 1);
            }
        }
        return true;
    }
};
