class Solution {
public:
    long long minSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.size())
                left[i] = st.top();
            st.push(i);
        }
        while (st.size()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.size())
                right[i] = st.top();
            st.push(i);
        }
        long long minn = 0;
        for (int i = 0; i < n; i++) {
            minn = minn + ((long long)(i - left[i]) * (long long)(right[i] - i) * (long long)arr[i]);
        }
        return minn;
    }
    long long maxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.size())
                left[i] = st.top();
            st.push(i);
        }
        while (st.size()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.size())
                right[i] = st.top();
            st.push(i);
        }
        long long maxx = 0;
        for (int i = 0; i < n; i++) {
            maxx = maxx + ((long long)(i - left[i]) * (long long)(right[i] - i) * (long long)arr[i]);
        }
        return maxx;
    }
    long long subArrayRanges(vector<int>& arr) {
        long long mn = minSum(arr);
        long long mx = maxSum(arr);
        cout << mx << " " << mn << endl;
        return (mx - mn);
    }
};
