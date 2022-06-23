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
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        
        if(!canFinish(n,p)) return {};
        
        vector<vector<int>> graph(n);
        
        int n1=p.size();
        
        vector<int> indeg(n,0);
        
        for(int i=0;i<n1;i++)
        {
            graph[p[i][0]].push_back(p[i][1]);
            indeg[p[i][1]]++;
        }
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({0,i});
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        
        int path=0;
        
        while(q.size())
        {
            int n1=q.size();
            for(int i=0;i<n1;i++)
            {
                int node=q.front();
                q.pop();
                
                for(int j=0;j<graph[node].size();j++)
                {
                    if(path+1>v[graph[node][j]].first)
                    {
                        
                        v[graph[node][j]].first=path+1;
                        q.push(graph[node][j]);
                    
                    }
                }              
                
            }
            path++;
        }
        sort(v.begin(),v.end());
        
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            res[i]=v[i].second;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};