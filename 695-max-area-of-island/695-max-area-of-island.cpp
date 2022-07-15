class Solution {
public:
    vector<vector<bool>> vis;
    
    int bfs(vector<vector<int>>& grid,int i,int j,int m,int n)
    {
        if(i>=m || i<0 || j>=n || j<0) return 0;
        if(vis[i][j]) return 0;
        
        if(grid[i][j]==0) return 0;
        
        vis[i][j]=true;
        
        return 1+bfs(grid,i,j+1,m,n)+bfs(grid,i,j-1,m,n)+bfs(grid,i+1,j,m,n)+bfs(grid,i-1,j,m,n);
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>> temp(m,vector<bool>(n,false));
        
        vis=temp;
        int res=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==false && grid[i][j]==1)
                {
                    int x=bfs(grid,i,j,m,n);
                    res=max(res,x);
                }
            }
        }
        
        return res;
        
    }
};