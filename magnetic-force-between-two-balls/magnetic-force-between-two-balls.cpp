class Solution {
public:
    int count(vector<int>& position, int minD)
    {
        int c=1,last=position[0];
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-last>=minD)
            {
                c++;
                last=position[i];
            }
        }
        return c;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start=1,end=1e9,mid,ans=-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            int c=count(position,mid);
            if(c>=m)
            {
                start=mid+1;
                
                ans=mid;
            }
            else
                end=mid-1;
        }
        return ans;
    }
};