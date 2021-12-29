class Solution {
public:
    vector<vector<int>>v;
    int solve(vector<vector<int>>& mat,int m,int n, int size)
    {
        int ans=INT_MAX;
        
        for(int i=size;i<=m;i++)
        {
            for(int j=size;j<=n;j++)
            {
                ans=min(ans,v[i][j]-v[i-size][j]-v[i][j-size]+v[i-size][j-size]);
            }
        }
        return ans;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size(),n=mat[0].size(),start=1,end=min(m,n),mid,ans=0;
        v=vector<vector<int>>(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                v[i][j]=-v[i-1][j-1]+v[i][j-1]+v[i-1][j]+mat[i-1][j-1];
            }
            
        }
        
        while(start<=end)
        {
            mid=start+(end-start)/2;
            
            int c=solve(mat,m,n,mid);
            if(threshold>=c)
            {
                ans=mid;
                start=mid+1;
            }
            else
                end=mid-1;
        }
        return ans;
    }
};