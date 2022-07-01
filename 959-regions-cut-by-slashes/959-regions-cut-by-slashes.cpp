class Solution {
public:
    int findParent(int node,vector<int>& par)
    {
        if(par[node]==node) return node;
        
        return par[node]=findParent(par[node],par);
    }
    void Union(int u,int v,vector<int>& par,vector<int>& size)
    {
        int pu=findParent(u,par);
        int pv=findParent(v,par);
        
        if(pu==pv) return;
        
        if(size[pu]>=size[pv])
        {
            size[pu]++;
            par[pv]=pu;
        }
        else
        {
            size[pv]++;
            par[pu]=pv;
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        
        int n1=n+1;
        
        vector<int> par(n1*n1),size(n1*n1,0);
        
        vector<vector<int>> g(n1,vector<int>(n1));
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n1;j++)
            {
                g[i][j]=i*n1+j;
                par[i*n1+j]=i*n1+j;
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<grid[i]<<endl;
        // }
        
        
        for(int i=0;i<n1-1;i++)
        {
            Union(g[i][0],g[i+1][0],par,size);
            // Union(g[i][n1-1],g[i+1][n1-1],par,size);
            Union(g[0][i],g[0][i+1],par,size);
            // Union(g[n1-1][i],g[n1-1][i+1],par,size);
        }
        for(int i=0;i<n1-1;i++)
        {
            // Union(g[i][0],g[i+1][0],par,size);
            Union(g[i][n1-1],g[i+1][n1-1],par,size);
            // Union(g[0][i],g[0][i+1],par,size);
            Union(g[n1-1][i],g[n1-1][i+1],par,size);
        }
        
        // for(int i=0;i<n1;i++)
        // {
        //     for(int j=0;j<n1;j++)
        //     {
        //         cout<<par[i*n1+j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        int ans=1;
        
        // return ans;
        
        for(int i=0;i<n;i++)
        {
            int idx=0;
            int j=0;
            while(idx<grid[i].size())
            {
                if(grid[i][idx]==' ')
                {
                    // cout<<"khali"<<endl;
                    idx++;
                    j++;
                    continue;
                }
                if(grid[i][idx]=='/')
                {
                    // cout<<"piche"<<endl;
                    int u=g[i][j+1];
                    int v=g[i+1][j];
                    
                    if(findParent(u,par)==findParent(v,par))
                    {
                        ans++;
                    }
                    else
                    {
                        Union(u,v,par,size);
                    }
                    idx++;
                    j++;
                    continue;
                }
                else
                {
                    // cout<<"samne"<<endl;
                    int u=g[i][j];
                    int v=g[i+1][j+1];
                    
                    if(findParent(u,par)==findParent(v,par))
                    {
                        ans++;
                    }
                    else
                    {
                        Union(u,v,par,size);
                    }
                    idx++;
                    j++;
                    continue;
                }
            }
        }
        
        // for(int i=0;i<n1;i++)
        // {
        //     for(int j=0;j<n1;j++)
        //     {
        //         cout<<par[i*n1+j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;
        
        
    }
};