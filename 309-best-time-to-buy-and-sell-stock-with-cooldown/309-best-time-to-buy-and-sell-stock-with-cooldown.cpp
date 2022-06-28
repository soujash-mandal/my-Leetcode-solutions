class Solution {
public:
    int fun(vector<int>& p,int idx,int start,vector<int> &dp)
    {
        if(idx>=p.size()) return 0;
        
        if(dp[start]!=-1) return dp[start];
        
        if(p[idx]<=p[start])
        {
            start=idx;
            return dp[start]=fun(p,idx+1,start,dp);
        }
        else
        {
            int res=fun(p,idx+1,start,dp);
            
            res=max(res,p[idx]-p[start]+fun(p,idx+2,idx+2,dp));
            
            return dp[start]=res;
        }
    }
    int maxProfit(vector<int>& p) {
        vector<int> dp(p.size(),-1);
        return fun(p,0,0,dp);
    }
};