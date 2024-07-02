class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1,zero=0,n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)zero++;
            else mul*=nums[i];
        }
        if(!zero)
        {
            for(int i=0;i<n;i++)
            {
                ans[i]=mul/nums[i];
            }
        }
        else if(zero==1)
        {
           for(int i=0;i<n;i++)
           {
               if(!nums[i])ans[i]=mul;
           }
        }
        return ans;
    }
};