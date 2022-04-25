class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n=circles.size(),c=0;
        int m[201][201];
        memset(m,0,sizeof(m));
        for(int i=0;i<n;i++)
        {
            int x=circles[i][0];
            int y=circles[i][1];
            int r=circles[i][2];
            for(int j=x-r;j<=x+r;j++)
            {
                for(int k=y-r;k<=y+r;k++)
                {
                    if(((j-x)*(j-x)+(k-y)*(k-y))<=r*r)
                        m[j][k]++;
                }
                    
            }
            
        }
        for(int i=0;i<201;i++)
        {
            for(int j=0;j<201;j++)
                if(m[i][j]>0)
                    c++;
        }
        return c;
    }
};