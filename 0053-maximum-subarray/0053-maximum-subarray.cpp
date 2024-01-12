class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx=-1000000000,sum=0,pos=-1000000000,n=nums.size();
    for(int i=0; i<n; i++)
    {
        pos=max(pos,nums[i]);
    }
    if(pos<0)return pos;
    else
    {

        for(int i=0; i<n; i++)
        {
            if(sum+nums[i]>=0)
            {
                sum+=nums[i];
            }
            else
            {
                sum=0;
            }
            maxx=max(maxx,sum);
        }
           return maxx;
    }
    
    }
    
};