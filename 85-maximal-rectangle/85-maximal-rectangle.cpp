class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&a,int l,int r)
    {
        if(l>r)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int ans=0,s=r-l+1,x=0,n=a.size();
        for(int i=1;i<n;i++)
        {
            if(a[i][r]-a[i][l-1]<s)
            {
                ans=max(ans,x*s);
                x=0;
                continue;
            }
            x++;
        }
        ans=max(ans,s*x);
        return dp[l][r]=max({ans,solve(a,l+1,r),solve(a,l,r-1)});
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>a(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                a[i][j]+=a[i][j-1]+(matrix[i-1][j-1]=='1');
            }
        }
        dp=vector<vector<int>>(m+1,vector<int>(m+1,-1));
        return solve(a,1,m);
        
    }
};