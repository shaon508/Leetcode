class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos = -1;
        for (int i = n - 2; i >= 0 && pos == -1; i--) {
            if (nums[i] < nums[i + 1]) {
                pos = i;
            }
        }
        if (pos == -1)
            reverse(nums.begin(), nums.end());
        else {
            for (int i = n - 1; i > pos; i--) {
                if (nums[pos] < nums[i]) {
                    swap(nums[pos], nums[i]);
                    break;
                }
            }
            sort(nums.begin()+pos+1,nums.end());
        }
    }
};