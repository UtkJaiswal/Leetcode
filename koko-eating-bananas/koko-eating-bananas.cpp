class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,end=1e9,mid,ans=-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            int c=0;
            for(int i=0;i<piles.size();i++)
            {
                c+=(int)ceil((1.0*piles[i])/(1.0*mid));
            }
            if(c<=h)
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