class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n=nums.size();
        int i=0,j=0;
        while(j<n)
        {
            while(dq.size()>0 && dq.back()<nums[j])
                dq.pop_back();
            dq.push_back(nums[j]);
            if(j-i+1<k)
                j++;
            else
            {
                ans.push_back(dq.front());
                if(dq.front()==nums[i])
                    dq.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};