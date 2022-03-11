class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int length=s.length();
        int start=0,end=length-1,ans=0;
        while(start<end)
        {
            int l=start,r=end;
            while(s[l]!=s[r])
                r--;
            
            if(l==r)
            {
                swap(s[r],s[r+1]);
                ans++;
                continue;
            }
            
            else
            {
                while(r<end)
                {
                    swap(s[r],s[r+1]);
                    r++;
                    ans++;
                }
            }
            start++;
            end--;
        }
        return ans;
        
    }
};