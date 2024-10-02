class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++) {
            if (st.size()) {
                if (st.top() > 0 && asteroids[i] < 0) {
                    while (st.size() && st.top() < abs(asteroids[i]) &&
                           (st.top() > 0 && asteroids[i] < 0)) {
                        st.pop();
                    }
                    if (st.size() && st.top() == abs(asteroids[i]) &&
                        st.top() * asteroids[i] < 0) {
                        st.pop();
                        continue;
                    }
                    if (!st.size() || st.top() < 0) {
                        st.push(asteroids[i]);
                    }
                } else {
                    st.push(asteroids[i]);
                }

            } else {
                st.push(asteroids[i]);
            }
        }
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};