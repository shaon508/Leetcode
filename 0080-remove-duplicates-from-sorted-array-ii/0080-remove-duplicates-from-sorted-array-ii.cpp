class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = 0, c;
        while (i < n) {
            j = i, c = 0;
            while (i < n && nums[i] == nums[j]) {
                c++;
                if (c <= 2) {
                    nums[k] = nums[j];
                    k++;
                }
                i++;
            }
        }
        return k;
    }
};