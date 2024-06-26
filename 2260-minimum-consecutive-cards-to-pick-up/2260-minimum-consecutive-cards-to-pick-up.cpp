class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<cards.size();i++)
        {
            if(mp[cards[i]]>0)
            {
                ans=min(ans,i-mp[cards[i]]+2); 
            } 
            mp[cards[i]]=i+1;
        }
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};