class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&a,int i,int j)
    {
        if(i>=n || j>=m)
            return INT_MAX;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i==n-1 && j==m-1)
        {
            if(a[i][j]<=0)
                return 1+abs(a[i][j]);
            return 1;
        }
        
        int ans=min(solve(a,i+1,j),solve(a,i,j+1))-a[i][j];
        return dp[i][j]=ans<=0?1:ans;
    }
    int calculateMinimumHP(vector<vector<int>>& a) {
        n=a.size(),m=a[0].size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return solve(a,0,0);
    }
};