class Solution {
public:
    int m,n;
    vector<int> dx={0,-1,0,1};
    vector<int> dy={1,0,-1,0};
    
    bool isValid(int i,int j)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }
    //joi ma kali
    bool dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<int>> &grid1,vector<vector<int>> &grid2)
    {
        
        // return 0;
        if(grid1[i][j]==0 && grid2[i][j])return 0;
        if(vis[i][j]) return true;
        
        vis[i][j]=1;
        
        bool ans=true;
        for(int k=0;k<4;k++)
        {
            int newX=i+dx[k];
            int newY=j+dy[k];
            if(isValid(newX,newY) && grid2[newX][newY])
            {
                if(dfs(newX,newY,vis,grid1,grid2)==0)
                    ans=false;
            }
        }
        return ans;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int ans=0;
        
        m=grid2.size();
        n=grid2[0].size();
        
        
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++)
        {
           for(int j=0;j<n;j++)
           {
               if(grid2[i][j] && !vis[i][j])
               {
                   if(dfs(i,j,vis,grid1,grid2))  
                     ++ans;
               }
           }
       }
       return ans;
    }
};