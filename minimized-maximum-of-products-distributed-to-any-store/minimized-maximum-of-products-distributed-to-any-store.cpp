class Solution {
public:
    int solve(vector<int>&quantities,int x)
    {
        int c=0;
        for(int i=0;i<quantities.size();i++)
            c+=ceil(1.0*quantities[i]/x);
        return c;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1,end=1e5,mid,ans=-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            int c=solve(quantities,mid);
            if(c<=n)
            {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
};