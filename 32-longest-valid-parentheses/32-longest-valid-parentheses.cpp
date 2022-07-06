class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    if(i-2>=0)
                        dp[i]=dp[i-2]+2;
                    else
                        dp[i]=2;
                }
                else
                {
                    int x=i-dp[i-1]-1;
                    if(x>=0)
                    {
                        if(s[x]=='(')
                        {
                            if(x-1>=0)
                                dp[i]=dp[x-1]+dp[i-1]+2;
                            else
                                dp[i]=dp[i-1]+2;
                        }
                    }
                    
                }
            }
            
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
        return ans;
    }
};