class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
{
    int n=nums.size(),minn=INT_MAX,i=0,j=0;
    long long int sum=0;
    while(i<n && j<=n)
    {
        if(sum >= target)
        {
            minn=min(minn,j-i);
            sum-=nums[i];
            i++;
        }
        else
        {
            if(j<n)
            {
                sum+=nums[j];
            }
            j++;
        }
    }
    if(minn==INT_MAX)return 0;
    else return minn;
}
};