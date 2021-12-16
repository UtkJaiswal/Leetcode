class Solution {
public:
    int solve(vector<int>&nums,int curr)
    {
        if(nums[curr]==curr)
            return curr;
        
        int next=nums[curr];
        nums[curr]=curr;
        
        return solve(nums,next);
    }
    int findDuplicate(vector<int>& nums) {
        return solve(nums,0);
    }
};