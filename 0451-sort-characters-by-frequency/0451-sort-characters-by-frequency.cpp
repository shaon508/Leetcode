class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        pair<int, int> freq[128];
        for (int i = 0; i < 128; i++) {
            freq[i].first = 0, freq[i].second = i;
        }
        for (char ch : s) {
            freq[(int)ch].first++;
        }
        sort(freq, freq + 125, greater<pair<int, int>>());
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < freq[i].first; j++) {
                ans += (char)freq[i].second;
            }
        }
        return ans;
    }
};