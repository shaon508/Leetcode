class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        string temp;
        unordered_map<string, vector<string>> mp;
        for (auto it : s) {
            temp = it;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(it);
        }
        vector<vector<string>> result;
        for (auto it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};