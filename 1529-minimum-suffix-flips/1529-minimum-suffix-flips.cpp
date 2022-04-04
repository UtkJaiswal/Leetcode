class Solution {
public:
    int minFlips(string target) {
        char next='0';
        int c=0,n=target.length();
        for(int i=0;i<n;i++)
        {
            if(target[i]!=next)
            {
                c++;
                if(next=='0')
                    next='1';
                else
                    next='0';
            }
        }
        return c;
    }
};