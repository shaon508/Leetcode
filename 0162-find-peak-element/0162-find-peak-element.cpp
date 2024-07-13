class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[1] < nums[0])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;
        int left = 1, right = n - 2, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return 0;
    }
};