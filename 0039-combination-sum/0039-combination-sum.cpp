class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    void fuc(vector<int>& v, int t, int id) {
        if (t == 0) {
            result.push_back(current);
            return;
        }
        if (id == v.size() || t < 0) {
            return;
        }
        // take
        current.push_back(v[id]);
        fuc(v, t - v[id], id);
        // not take
        current.pop_back();
        fuc(v, t, id + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        fuc(candidates, target, 0);
        return result;
    }
};