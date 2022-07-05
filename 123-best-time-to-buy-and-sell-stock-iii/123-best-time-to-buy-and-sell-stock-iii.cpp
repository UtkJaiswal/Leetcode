class Solution {
public:
    int maxProfit(vector<int>& A) {
        int n=A.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<2;j++)
    //     dp[i][j][0]=0;
    // }
    for(int c=0;c<2;c++)
    {
        for(int left=1;left<=2;left++)
        {
            dp[n][c][left-1]=0;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int c=0;c<2;c++)
        {
            for(int left=2;left>=1;left--)
            {
                if(c==0)
                dp[i][c][left-1]=max(-A[i]+dp[i+1][1][left-1],dp[i+1][0][left-1]);
                else
                {
                    if(left-2>=0)
                    dp[i][c][left-1]=max(A[i]+dp[i+1][0][left-2],dp[i+1][1][left-1]);
                    else
                    dp[i][c][left-1]=max(A[i]+0,dp[i+1][1][left-1]);
                }
                
            }
        }
    }
    return dp[0][0][1];
        
    }
};