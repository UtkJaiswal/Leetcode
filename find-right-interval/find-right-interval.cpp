class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++)
        {
            int start=i,end=n-1,mid,c=-1;
            while(start<=end)
            {
                mid=start+(end-start)/2;
                if(intervals[mid][0]>=intervals[i][1])
                {
                    c=intervals[mid][2];
                    end=mid-1;
                }
                else
                    start=mid+1;
            }
            if(c==-1)
                ans[intervals[i][2]]=-1;
            else
                ans[intervals[i][2]]=c;
        }
        return ans;
    }
};