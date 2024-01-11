class Solution {
public:
   int distMoney(int money, int children)
{
    int ans=0;
    if(money==children*8)ans=children;
    else if(money>children*8)ans=children-1;
    else if(money<children  || (children==1 && money==4))ans=-1;
    else
    {
        while(money-8>0 && children>0 && money>children)
        {
            ans++;
            money-=8;
            children--;
        }
        if((money==4 && children==1) || money<children)ans--;
        ans=max(ans,0);
    }
    return ans;
}
};