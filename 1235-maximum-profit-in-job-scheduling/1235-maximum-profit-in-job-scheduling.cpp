class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<vector<int>> v;
        
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            v.push_back({e[i],s[i],p[i]});
        }
        
        
        sort(v.begin(),v.end());
        
        map<int,int> dp;
        
        vector<int> vec;
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            
            int i1=v[i][1];
            int i2=v[i][0]-1;
            
            int idx1=upper_bound(vec.begin(),vec.end(),i1)-vec.begin();
            idx1--;
            
            int x=0;
            if(idx1>=0)
            {
                x=dp[vec[idx1]];
            }
            
            int idx2=upper_bound(vec.begin(),vec.end(),i2)-vec.begin();
            idx2--;
            
            int y=0;
            if(idx2>=0)
            {
                y=dp[vec[idx2]];
            }
            
            dp[v[i][0]]=max(dp[v[i][0]],max(x+v[i][2],y));
            res=max(res,dp[v[i][0]]);
            
            vec.push_back(v[i][0]);
        }
        
        return res;
        
    }
};