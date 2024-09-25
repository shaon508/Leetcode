class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, n, 0, 0, "");
        return ans;
    }
    void solve(vector<string>& ans, int n, int openBracket, int closeBracket,
               string curr) {
        if (curr.size() == n * 2) {
            ans.push_back(curr);
            return;
        }
        if (openBracket < n)
            solve(ans, n, openBracket + 1, closeBracket, curr + "(");
        if (closeBracket < openBracket)
            solve(ans, n, openBracket, closeBracket + 1, curr + ")");
    }
};