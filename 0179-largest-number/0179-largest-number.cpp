class Solution {
private:
    string Atoi(int num) {
        string s = "";
        if (num == 0)
            s.push_back('0');
        while (num > 0) {
            s.push_back(num % 10 + '0');
            num /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> s;
        string ans;
        for (int i = 0; i < n; i++) {
            s.push_back(Atoi(nums[i]));
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] + s[j] > s[j] + s[i]) {
                    swap(s[i], s[j]);
                }
            }
        }
        if (s[n - 1] == "0")
            ans += s[n - 1];
        else {
            for (int i = n - 1; i >= 0; i--) {
                ans += s[i];
            }
        }
        return ans;
    }
};