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
            par[pv]=pu;
            size[pu]++;
        }
        else
        {
            par[pu]=pv;
            size[pv]++;
        }
    }
    
    bool equationsPossible(vector<string>& eq) {
        int n=eq.size();
        
        vector<int> par(26),size(26,0);
        for(int i=0;i<26;i++) par[i]=i;
        
        for(int i=0;i<n;i++)
        {
            if(eq[i][1]=='=')
            {
                Union(eq[i][0]-'a',eq[i][3]-'a',par,size);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(eq[i][1]=='!')
            {
                int pu=findParent(eq[i][0]-'a',par);
                int pv=findParent(eq[i][3]-'a',par);
                
                if(pu==pv) return false;
            }
        }
        
        return true;
    }
};