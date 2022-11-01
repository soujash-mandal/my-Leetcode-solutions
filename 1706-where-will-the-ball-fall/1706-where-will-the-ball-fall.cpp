class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=i;
        
        
        for(int i=0;i<m;i++)
        {
            
            vector<int> temp(n,-1);
            for(int j=0;j<n-1;j++)
            {
                if(grid[i][j]==1)
                {
                    if(grid[i][j+1]==1)
                    {
                        temp[j+1]=v[j];
                    }
                }
            }
            for(int j=1;j<n;j++)
            {
                if(grid[i][j]==-1)
                {
                    if(grid[i][j-1]==-1)
                    {
                        temp[j-1]=v[j];
                    }
                }
            }
            v=temp;
        }
        vector<int> res(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[j]==i)
                {
                    res[i]=j;
                }
            }
        }
        return res;
    }
};