class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int l1 = a.size(), l2 = b.size();
        if (l1 > l2)
            return findMedianSortedArrays(b, a); // Swap to ensure l1 <= l2
        int low = 0, high = l1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int baki = (l1 + l2 + 1) / 2 - mid;

            int tt1 = (mid == 0) ? INT_MIN : a[mid - 1];
            int r1 = (mid == l1) ? INT_MAX : a[mid];
            int tt2 = (baki == 0) ? INT_MIN : b[baki - 1];
            int r2 = (baki == l2) ? INT_MAX : b[baki];

            if (tt1 <= r2 && tt2 <= r1) {
                if ((l1 + l2) % 2 == 1)
                    return max(tt1, tt2);
                else
                    return (max(tt1, tt2) + min(r1, r2)) / 2.0;
            } else if (tt1 > r2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return 0.0;
    }
};
