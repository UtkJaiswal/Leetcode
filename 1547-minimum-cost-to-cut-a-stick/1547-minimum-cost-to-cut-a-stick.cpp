class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&cuts,int l,int r)
    {
        if(r==l)
            return 0;
        
        if(r-l==1)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int ans=INT_MAX,s=cuts[l],e=cuts[r];
        
        for(int i=l+1;i<r;i++)
        {
            int temp=e-s+solve(cuts,l,i)+solve(cuts,i,r);
            ans=min(ans,temp);
        }
        
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int p=cuts.size();
        dp=vector<vector<int>>(p+1,vector<int>(p+1,-1));
        return solve(cuts,0,cuts.size()-1);
    }
};