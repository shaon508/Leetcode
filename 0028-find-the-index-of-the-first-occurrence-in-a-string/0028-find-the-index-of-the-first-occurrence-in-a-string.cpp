class Solution {
public:
    int strStr(string s, string t) {
        int n=s.size(),m=t.size(),i=0,j,k,c=0;
        while(i+m<=n)
        {
           j=i,c=0,k=0;
            while((j<n && k<m) && s[j]==t[k])
            {
                j++,k++,c++;
            }
            if(c==m)return i;
            i++;
        }
        return -1;
    }
};