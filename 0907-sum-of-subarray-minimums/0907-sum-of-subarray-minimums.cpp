class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = (int)1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left_count = i - left[i];
            long long right_count = right[i] - i;
            ans = (ans + (left_count * right_count % mod) * arr[i] % mod) % mod;
        }

        return (int)ans;
    }
};
