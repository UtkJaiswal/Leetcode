class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rect, vector<vector<int>>& points) 
    {
        unordered_map<int, vector<int>> htl;
        // maps heights to all the lengths of rectangles with that height
        
        for(int i=0; i<rect.size(); i++){       
            htl[rect[i][1]].push_back(rect[i][0]);
        }
        
		// have to sort the containers to apply binary search
        for(int i=0; i<=100; i++){
            sort(htl[i].begin(), htl[i].end());
        }
        
		
        vector<int> ans;
		
        for(vector<int> p: points){
            int x=p[0], y=p[1];
            int ct=0;
            for(int j= y; j<=100; j++){
                if(htl.find(j)!=htl.end()){
                    int xxx=lower_bound(htl[j].begin(),htl[j].end(),x)-htl[j].begin();
                    //if(xxx==-1) xxx=0;
                    ct+= htl[j].size()- xxx;
                    //ct+= lower_bound(htl[j].begin(),htl[j].end(),x)-htl[j].begin();
					// binary search return the idx in array from which the values are >= x
					// the values at this and right of this are the lengths possible
					// so substract by size of array to get the number
                }
            }
            
            ans.push_back(ct);
            
        }
        
        return ans;    
    }
};