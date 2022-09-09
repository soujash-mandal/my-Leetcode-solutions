class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        
        for(int i=2;i<=n;i++)
        {
            int res=0;
            for(int j=1;j<i;j++)
            {
                res=max(res,j*max(dp[i-j],i-j));
            }
            dp[i]=res;
        }
        
        return dp[n];
    }
};