class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node,vector<bool> &vis,vector<bool> &v)
    {
        if(vis[node]==true) return false;
    
        if(v[node]==true) return true;
        
        vis[node]=true;
        v[node]=true;
        
        bool res=true;
        for(int i=0;i<graph[node].size();i++)
        {
            res=res & dfs(graph,graph[node][i],vis,v); 
        }
        
        vis[node]=false;
        
        return res;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n);
        
        int n1=p.size();
        
        for(int i=0;i<n1;i++)
        {
            graph[p[i][0]].push_back(p[i][1]);
        }
        
        vector<bool> v(n,false);
        
        // vector<bool> vis(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(v[i]==true)
            {
                continue;
            }
            vector<bool> vis(n,false);
            
            bool res=dfs(graph,i,vis,v);
            
            // if(res)
            // {
            //     cout<<i<<endl;
            //     for(int j=0;j<n;j++)
            //     {
            //         if(v[j]==true) cout<<j<<" ";
            //     }
            // }
            
            if(!res)
            {
                // cout<<i<<endl;
                // for(int j=0;j<n;j++)
                // {
                //     if(v[j]==true) cout<<j<<" ";
                // }
                return false;
            }
        }
        
        return true;
    }
};