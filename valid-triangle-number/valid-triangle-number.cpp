class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int start=j+1,end=n-1,mid,c=-1;
                while(start<=end)
                {
                    mid=start+(end-start)/2;
                    if(nums[mid]<nums[i]+nums[j])
                    {
                        c=mid;
                        start=mid+1;
                    }
                    else
                        end=mid-1;
                }
                if(c!=-1)
                    ans+=c-j;
            }
        }
        return ans;
    }
};