class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), mn = INT_MAX, ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1, sum;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum <= target) {
                    if (target - sum < mn) {
                        mn = target - sum;
                        ans = sum;
                    }
                    left++;
                } else {
                    if (sum - target < mn) {
                        mn = sum - target;
                        ans = sum;
                    }
                    right--;
                }
            }
        }
        return ans;
    }
};