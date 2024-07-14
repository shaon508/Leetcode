class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> ump;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            ump[nums2[i]] = (st.size() == 0) ? -1 : st.top();
            st.push(nums2[i]);
        }
        for (auto it : nums1)
            ans.push_back(ump[it]);
        return ans;
    }
};