class Solution {
public:
    long long fun(vector<vector<int>> &graph,int node,vector<bool>& vis)
    {
        if(vis[node]==true) return 0;
        
        vis[node]=true;
        long long res=1;
        
        for(int i=0;i<graph[node].size();i++)
        {
            res+=fun(graph,graph[node][i],vis);
        }
        
        return res;
    }
    
    long long countPairs(int n, vector<vector<int>>& e) {
        int n1=e.size();
        
        vector<vector<int>> graph(n);
        vector<bool> vis(n,false);
        
        for(int i=0;i<n1;i++)
        {
            graph[e[i][0]].push_back(e[i][1]);
            graph[e[i][1]].push_back(e[i][0]);
        }
        
        vector<long long> v;
        
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                long long x=fun(graph,i,vis);
                v.push_back(x);
            }
        }
        
        long long res=0;
        
        
        n1=v.size();
        vector<long long> suf(n1,0);
        
        suf[n1-1]=v[n1-1];
        for(long long i=n1-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+v[i];
        }
        
        for(long long i=0;i<n1-1;i++)
        {
            res+=v[i]*(suf[i+1]);
        }
        
        return res;
        
    }
};