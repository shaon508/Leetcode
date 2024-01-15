class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn=INT_MAX,ans=0;
        for(int i=0;i<prices.size();i++)
        {
            ans=max(prices[i]-minn,ans);
            minn=min(minn,prices[i]);
        }
        return ans;
    }
};