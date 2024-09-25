class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;

        if (digits.empty()) {
            return ans;
        }
        ans.push_back(""); 
        for (auto digit : digits) {
            vector<string> temp;
            string chars = v[digit - '0'];
            for (auto s : ans) {
                for (auto c : chars) {
                    temp.push_back(s + c);
                }
            }
            ans = temp;
        }

        return ans;
    }
};
