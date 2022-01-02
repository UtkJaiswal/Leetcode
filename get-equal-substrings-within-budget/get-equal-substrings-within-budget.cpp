class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int ans=0,i=0,j=0;
        while(j<n)
        {
            while(maxCost-abs(s[j]-t[j])<0 and i<j)
            {
                maxCost+=abs(s[i]-t[i]);
                i++;
            }
            if(maxCost-abs(s[j]-t[j])<0)
            {
                i++;
                j++;
                continue;
            }
            ans=max(ans,j-i+1);
            maxCost-=abs(s[j]-t[j]);
            j++;
        }
        
        return ans;
    }
};