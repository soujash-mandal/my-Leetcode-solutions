class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        // vector<vector<bool>> vis(m,vector<int>(n,false));        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        // cout<<q.front().first<<" "<<q.front().second<<endl;
        // return 0;
        
        int res=0;
        
        while(q.size())
        {
            int n1=q.size();
            bool check=false;
            
            for(int i=0;i<n1;i++)
            {
                pair<int,int> pos;
                pos=q.front();
                q.pop();
                
                int x=pos.first;
                int y=pos.second;
                
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    check=true;
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                }
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    check=true;
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                }
                if(x+1<m && grid[x+1][y]==1)
                {
                    check=true;
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                }
                if(y+1<n && grid[x][y+1]==1)
                {
                    check=true;
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                }
            }
            if(check)
                res++;
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        
        return res;
    }
};