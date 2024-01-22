class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n=v.size()-1;
        if(n==0)return v[0];
        sort(v.begin(),v.end());
        return v[n/2];
    }
};