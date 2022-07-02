class Solution {
public:
    int findParent(int node,vector<int>& par)
    {
        if(node==par[node]) return node;
        
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
    int makeConnected(int n, vector<vector<int>>& c) {
        
        if(c.size()<n-1) return -1;
        
        vector<int> par(n),size(n,0);
        
        for(int i=0;i<n;i++) par[i]=i;
        
        for(int i=0;i<c.size();i++)
        {
            Union(c[i][0],c[i][1],par,size);
        }
        
        set<int> s;
        
        for(int i=0;i<n;i++)
        {
            s.insert(findParent(par[i],par));
        }
        
        return s.size()-1;
    }
};