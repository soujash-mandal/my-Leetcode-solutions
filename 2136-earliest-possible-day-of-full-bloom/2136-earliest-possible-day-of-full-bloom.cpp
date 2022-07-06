class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n=p.size();
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({g[i],p[i]});
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        int x=0;
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            x+=v[i].second;
            res=max(res,x+v[i].first);
        }
        
        return res;
    }
};