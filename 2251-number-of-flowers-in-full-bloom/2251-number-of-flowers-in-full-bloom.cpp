class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n=persons.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
            v.push_back({persons[i],i});
        sort(v.begin(),v.end());
        sort(flowers.begin(),flowers.end());
        vector<int>ans(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int index=0;
        for(int i=0;i<n;i++)
        {
            while(index<flowers.size() && flowers[index][0]<=v[i].first)
            {
                pq.push({flowers[index][1],flowers[index][0]});
                index++;
            }
            while(!pq.empty() && pq.top().first<v[i].first)
                pq.pop();
            
            ans[v[i].second]=pq.size();
            
        }
        return ans;
    }
};