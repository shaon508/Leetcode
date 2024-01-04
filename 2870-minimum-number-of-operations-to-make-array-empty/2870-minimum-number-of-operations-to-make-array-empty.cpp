class Solution {
public:
    int minOperations(vector<int>& v) {
        sort(v.begin(),v.end());
    int i=0,c,j,ans=0,n=v.size();
    while(i<n && ans!=-1)
    {
        j=i,c=0;
        while(i<n && v[i]==v[j] && ans!=-1)
        {
            c++;
            i++;
        }
        if(c==1)
        {
            ans=-1;
        }
        else
        {
            if(c%3==1)c++;
            ans+=(c/3);
            ans+=(c%3)/2;
        }
    }
    return ans;
    }
};