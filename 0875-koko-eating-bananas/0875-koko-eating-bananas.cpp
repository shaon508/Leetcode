class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int left = 1, right = 1e9, mid, countt = 0, n = piles.size(), ans;
        while (left <= right) {
            mid = (left + right) / 2;
            countt = 0;
            for (int i = 0; i < n; i++) {
                countt += (piles[i] / mid) + (piles[i] % mid > 0);
            }
            if (countt <= h) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};