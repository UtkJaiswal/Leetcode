class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int>ans;
        vector<int>start,end;
        for(auto flower:flowers)
        {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(int i=0;i<persons.size();i++)
        {
            int started=upper_bound(start.begin(),start.end(),persons[i])-start.begin();
            int ended=lower_bound(end.begin(),end.end(),persons[i])-end.begin();
            ans.push_back(started-ended);
        }
        return ans;
    }
};