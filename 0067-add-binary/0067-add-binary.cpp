class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int temp = 0, sum = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0) {
            sum = temp;
            if (i >= 0) {
                sum += (a[i] - '0');
                i--;
            }
            if (j >= 0) {
                sum += (b[j] - '0');
                j--;
            }
            ans.push_back((sum % 2) + '0');
            temp = sum / 2;
        }
        if (temp) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};