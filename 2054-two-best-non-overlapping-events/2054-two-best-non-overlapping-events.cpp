class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int n=e.size();
        for(int i=0;i<n;i++) swap(e[i][0],e[i][1]);
        
        sort(e.begin(),e.end());
        set<int> s;
        map<int,int> mp;
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            res=max(res,e[i][2]);
            auto it=s.lower_bound(e[i][1]);
            if(it!=s.begin())
            {
                it--;
                res=max(res,mp[*it]+e[i][2]);
            }
            s.insert(e[i][0]);
            mp[e[i][0]]=max(mp[e[i][0]],e[i][2]);
            if(i>0)
            {
                mp[e[i][0]]=max(mp[e[i][0]],mp[e[i-1][0]]);
            }
        }
        
        return res;
    }
};