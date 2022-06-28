class Solution {
public:
    int fun(vector<int>& p,int idx,int start,int fee,vector<int> &dp)
    {
        int n=p.size();
        if(idx==n) return 0;
        
        if(dp[start]!=-1) return dp[start];
        
        if(p[idx]<=p[start])
        {
            start=idx;
            return dp[start]=fun(p,idx+1,start,fee,dp);
        }
        else
        {
            int res=fun(p,idx+1,start,fee,dp);
            
            if(p[idx]-p[start]>fee)
            {
                res=max(res,p[idx]-p[start]-fee+fun(p,idx+1,idx+1,fee,dp));
            }
            
            return dp[start]=res;
        }
    }
    int maxProfit(vector<int>& p, int fee) {
        vector<int> dp(p.size(),-1);
        
        return fun(p,0,0,fee,dp);
    }
};