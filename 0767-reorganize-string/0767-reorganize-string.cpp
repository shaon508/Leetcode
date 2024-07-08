class Solution {
public:
    string reorganizeString(string s) {
        vector<int> v(26, 0);
        int n = s.size(), maxx = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            int num = s[i] - 'a';
            v[num]++;
            if (v[num] > maxx) {
                maxx = v[num];
                temp = num;
            }
        }
        if (maxx > (n + 1) / 2) {
            return "";
        }
        string result(n, ' ');
        int index = 0;
        while (v[temp] > 0) {
            result[index] = temp + 'a';
            index += 2;
            v[temp]--;
        }
        for (int i = 0; i < 26; i++) {
            while (v[i] > 0) {
                if (index >= n) {
                    index = 1;
                }
                result[index] = i + 'a';
                index += 2;
                v[i]--;
            }
        }

        return result;
    }
};
