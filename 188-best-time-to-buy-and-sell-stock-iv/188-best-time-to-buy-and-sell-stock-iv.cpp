class Solution {
public:
    int fun(vector<int>& p,int idx,int start,int k,vector<vector<int>>& dp)
    {
        if(k==0) return 0;
        if(idx>=p.size()) return 0;
        
        
        if(dp[start][k]!=-1) return dp[start][k];
        
        if(p[idx]<=p[start])
        {
            start=idx;
            return dp[start][k]=fun(p,idx+1,start,k,dp);
        }
        else
        {
            int res=fun(p,idx+1,start,k,dp);
            
            res=max(res,p[idx]-p[start]+fun(p,idx+1,idx+1,k-1,dp));
            
            return dp[start][k]=res;
        }
    }
    
    int maxProfit(int k, vector<int>& p) {
        vector<vector<int>> dp(p.size(),vector<int>(k+1,-1));
        
        return fun(p,0,0,k,dp);
    }
};