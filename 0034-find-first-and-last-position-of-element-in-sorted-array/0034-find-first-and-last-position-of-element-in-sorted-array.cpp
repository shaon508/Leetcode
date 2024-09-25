class Solution {
public:
    int binarySearch(vector<int>& arr, int l, int r, int t) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] < t) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> v(2, -1);
        if (arr.empty())
            return v;

        int left = 0, right = arr.size() - 1;
        int start = binarySearch(arr, left, right, target);
        int end = binarySearch(arr, left, right, target + 1) - 1;
        if (start <= end && start < arr.size() && arr[start] == target) {
            v[0] = start;
            v[1] = end;
        }

        return v;
    }
};
