class Solution {
public:
    int MAX(int a, int b) {
        if (a > b)
            return a;
        return b;
    }
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push('(');
            }
            if (st.size() > 0) {
                ans = MAX(ans, st.size());
            }
            if (st.size() > 0 && s[i] == ')')
                st.pop();
        }
        return ans;
    }
};