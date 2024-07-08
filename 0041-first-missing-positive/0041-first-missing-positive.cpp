class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), id;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0)
                nums[i] = n + 1;
        }
        for (int i = 0; i < n; i++) {
            id = abs(nums[i]) - 1;
            if (id < n && nums[id] > 0) {
                nums[id] *= -1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};