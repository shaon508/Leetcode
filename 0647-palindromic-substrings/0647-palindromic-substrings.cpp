class Solution {
public:
    int numOfPalid(string s, int i, int j , int n) {
        int cnt = 0;
        int left = i , right = j;
        while(left >=0 && right<n && s[left]==s[right])
        {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0, cnt;
        for (int i = 0; i < n; i++) {
            //for odd case;
            cnt = numOfPalid(s, i, i , n);
            //for even case;
            cnt += numOfPalid(s, i-1, i , n);
            ans += cnt;
        }
        return ans;
    }
};