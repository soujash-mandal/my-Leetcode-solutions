class Solution {
public:
    int res=0;
    
    int fun(vector<vector<int>>& tree, string &s,int root)
    {
        
        vector<int> v(2,0);
        
        for(int i=0;i<tree[root].size();i++)
        {
            int x=fun(tree,s,tree[root][i]);
            res=max(res,x);
            
            if(s[root]!=s[tree[root][i]])
            {
                
                v.push_back(x);
            }
        }
        
        sort(v.begin(),v.end());
        
        
        // cout<<v[v.size()-1]<<" ";
        res=max(res,1+v[v.size()-1]+v[v.size()-2]);
        
        return 1+v[v.size()-1];
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        
        vector<vector<int>> tree(n);
        
        int root=0;
        
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            {
                root=i;
            }
        }
        // cout<<root<<endl;
        
        for(int i=0;i<n;i++)
        {
            if(parent[i]!=-1)
            {
                tree[parent[i]].push_back(i);
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<tree[i].size();j++)
        //     {
        //         cout<<tree[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int x=fun(tree,s,root);
        
        return res;
        
    }
};