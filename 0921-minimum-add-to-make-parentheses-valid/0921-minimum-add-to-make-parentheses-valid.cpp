class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        if(n == 0) return NULL;
        stack <char> st;
        for(int i = 0 ; i < n ; i++)
        {
            if(st.size() > 0 && st.top() == '(' && s[i] ==')')
            {
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.size();
    }
};