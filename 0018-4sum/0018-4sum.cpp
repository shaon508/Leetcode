class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        long long sum;
        vector<vector<int>> ans;
        vector<int> temp;
        int n = arr.size();
        map<vector<int>, int> mp;
        sort(arr.begin(), arr.end());
        for (int i = 0; i + 3 < n; i++) {
            for (int j = i + 1; j + 2 < n; j++) {
                int left = j + 1, right = n - 1;
                while (left < right) {
                    sum = (long long)arr[i] + (long long)arr[j] +
                          (long long)arr[left] + (long long)arr[right];
                    if (sum == target) {
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[left]);
                        temp.push_back(arr[right]);
                        if (!mp[temp]) {
                            ans.push_back(temp);
                        }
                        mp[temp]++;
                        temp.clear();
                        left++;
                    } else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return ans;
    }
};