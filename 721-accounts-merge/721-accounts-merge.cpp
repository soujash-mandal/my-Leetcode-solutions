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
    vector<vector<string>> accountsMerge(vector<vector<string>>& ac) {
        map<string,int> mp;
        map<string,string> father;
        vector<string> accid;
        
        int x=1;
        int n=ac.size();
        vector<int> par;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<ac[i].size();j++)
            {
                if(mp[ac[i][j]]==0)
                {
                    mp[ac[i][j]]=x;
                    father[ac[i][j]]=ac[i][0];
                    par.push_back(x-1);
                    accid.push_back(ac[i][j]);
                    x++;
                }
            }
        }
        x--;
        
        
        for(auto it:mp)
        {
            mp[it.first]--;
        }
        
        
        vector<int> size(x,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<ac[i].size()-1;j++)
            {
                Union(mp[ac[i][j]],mp[ac[i][j+1]],par,size);
            }
        }
        
        vector<vector<string>> res;
        map<int,vector<string>> mpp;
        
        for(int i=0;i<x;i++)
        {
            mpp[findParent(i,par)].push_back(accid[i]);
        }
        
        
        for(auto it:mpp)
        {
            res.push_back(it.second);
        }
        
        n=res.size();
        for(int i=0;i<n;i++)
        {
            res[i].push_back(father[res[i][0]]);
            reverse(res[i].begin(),res[i].end());
            sort(res[i].begin()+1,res[i].end());
        }
        return res;
        
        
    }
};