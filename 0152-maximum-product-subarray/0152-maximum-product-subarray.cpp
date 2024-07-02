class Solution {
public:
    int maxProduct(vector<int>& nums) {
      long long int  ans=INT_MIN,pre=1,post=1,n=nums.size();
       for(int i=0;i<n;i++)
       {
           if(pre==0 || pre<INT_MIN)pre=1;
           if(post==0 || post<INT_MIN)post=1;
           
           pre*=nums[i];
           post*=nums[n-i-1];
           
           ans=max(ans,max(pre,post));
       }
        
        return ans;
    }
};