class Solution {
public:
    int solve(vector<int>&arr,int x)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>x)
                sum+=x;
            else
                sum+=arr[i];
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int start=0,end=1e5,mid,ans=-1,diff=target;
        for(int i=0;i<arr.size();i++)
            ans=max(ans,arr[i]);
        end=ans;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            int c=solve(arr,mid);
            if(abs(c-target)<diff)
            {
                ans=mid;
                
                diff=abs(c-target);
            }
            else if(abs(c-target)==diff)
                ans=min(ans,mid);
            if(c>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return ans;
    }
};