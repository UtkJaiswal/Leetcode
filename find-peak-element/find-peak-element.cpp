class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int start=0,end=nums.size()-1,mid,ans=-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(mid==0 and nums[mid]>nums[1])
                return 0;
            else if(mid==nums.size()-1 and nums[mid]>nums[mid-1])
                return nums.size()-1;
            
            if(mid>0 and mid<nums.size()-1 and nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
                return mid;
            else if(mid>0 and nums[mid-1]>nums[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
};