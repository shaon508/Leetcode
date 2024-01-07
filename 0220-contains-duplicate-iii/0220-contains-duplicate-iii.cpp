class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        int n = nums.size();
        pair<int, int> p[n + 5];
        for (int i = 0; i < n; i++) {
            p[i].first = nums[i], p[i].second = i;
        }
        sort(p, p + n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (p[j].first - p[i].first > valueDiff)
                    break;
                else if (abs(p[j].second - p[i].second) <= indexDiff)
                    return true;
            }
        }
        return false;
    }
};