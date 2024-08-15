class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), temp, max1 = 0, max2 = 0, pre = 0;
        for (int i = 0; i < n - 1; i++) {
            temp = pre;
            pre = max1;
            max1 = max(temp + nums[i], pre);
        }
        pre = 0;
        for (int i = 1; i < n; i++) {
            temp = pre;
            pre = max2;
            max2 = max(temp + nums[i], pre);
        }
        if(n == 1) return nums[0];
        return max(max1, max2);
    }
};