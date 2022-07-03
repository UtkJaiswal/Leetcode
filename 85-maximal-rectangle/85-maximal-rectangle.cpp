class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            a[0][i]=matrix[0][i]=='1';
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                    a[i][j]=a[i-1][j]+1;
                else
                    a[i][j]=0;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            stack<int>st;
            vector<int>l(m,0);
            vector<int>r(m,0);
            for(int j=0;j<m;j++)
            {
                while(!st.empty() && a[i][st.top()]>=a[i][j])
                    st.pop();
                
                if(st.empty())
                    l[j]=-1;
                else
                    l[j]=st.top();
                
                st.push(j);
            }
            while(!st.empty())
                st.pop();
            for(int j=m-1;j>=0;j--)
            {
                while(!st.empty() && a[i][st.top()]>=a[i][j])
                    st.pop();
                
                if(st.empty())
                    r[j]=m;
                
                else
                    r[j]=st.top();
                
                st.push(j);
            }
            
            for(int j=0;j<m;j++)
            {
                ans=max(ans,(r[j]-l[j]-1)*a[i][j]);
            }
        }
        return ans;
        
    }
};