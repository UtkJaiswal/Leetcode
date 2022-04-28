class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rect, vector<vector<int>>& points) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<rect.size();i++)
        {
            m[rect[i][1]].push_back(rect[i][0]);
        }
        
        for(int i=1;i<=100;i++)
            sort(m[i].begin(),m[i].end());
        
        vector<int>ans;
        for(auto itr:points)
        {
            int x=itr[0];
            int y=itr[1];
            int c=0;
            for(int j=y;j<=100;j++)
            {
                if(m.count(j))
                {
                    int p=lower_bound(m[j].begin(),m[j].end(),x)-m[j].begin();
                    // cout<<j<<" "<<p<<endl;
                    c+=m[j].size()-p;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};