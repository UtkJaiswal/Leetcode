class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),start=0,end=n-1,mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            int maxR=0;
            for(int i=0;i<m;i++)
            {
                if(mat[i][mid]>mat[maxR][mid])
                    maxR=i;
            }
            if((mid==0 || mat[maxR][mid]>mat[maxR][mid-1]) and (mid==n-1 || mat[maxR][mid]>mat[maxR][mid+1]))
                return vector<int>{maxR,mid};
            else if(mid>0 and mat[maxR][mid]<mat[maxR][mid-1])
                end=mid-1;
            else
                start=mid+1;
        }
        return vector<int>{-1,-1};
    }
};