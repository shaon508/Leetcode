class Solution {
public:
    bool canJump(vector<int>& arr) {
        int reach = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            if (reach < i)
                return false;
            reach = max(arr[i] + i, reach);
        }
        return true;
    }
};