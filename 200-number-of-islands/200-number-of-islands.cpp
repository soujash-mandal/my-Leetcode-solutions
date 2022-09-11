class Solution {
public:
    
     vector<vector<bool>> vis;
    
    int dfs(vector<vector<char>>& grid,int i,int j,int m,int n)
    {
        if(i>=m || i<0 || j>=n || j<0) return 0;
        if(vis[i][j]) return 0;
        
        if(grid[i][j]=='0') return 0;
        
        vis[i][j]=true;
        
        return 1+dfs(grid,i,j+1,m,n)+dfs(grid,i,j-1,m,n)+dfs(grid,i+1,j,m,n)+dfs(grid,i-1,j,m,n);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>> temp(m,vector<bool>(n,false));
        
        vis=temp;
        
        int res=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==false && grid[i][j]=='1')
                {
                    int x=dfs(grid,i,j,m,n);
                    res++;
                }
            }
        }
        
        return res;
    }
};