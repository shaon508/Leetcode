class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans = "";
        for (int i = 0; i < num.size(); i++) {
            while (k && st.size() && st.top() > num[i]) {
                st.pop();
                k--;
            }
            if (st.size() || num[i] != '0')
                st.push(num[i]);
        }
        while(k && st.size())
        {
            k--;
            st.pop();
        }
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans.size() ? ans : "0";
    }
};