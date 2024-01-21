class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),left,right,mid;
        for(int i=0;i<n;i++)
        {
            left=0,right=m-1;
            for(int j=0;j<m;j++)
            {
                while(left<=right)
                {
                    mid=(left+right)/2;
                    if(matrix[i][mid]==target)return true;
                    else if(matrix[i][mid]<target)left=mid+1;
                    else right=mid-1;
                }
            }
        }
        return false;
    }
};