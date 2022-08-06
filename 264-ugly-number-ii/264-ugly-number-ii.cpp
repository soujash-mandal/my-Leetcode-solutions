class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1]=1;
        
        int x2=1;
        int x3=1;
        int x5=1;
        
        
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=min({dp[x2]*2,dp[x3]*3,dp[x5]*5});
            
            if(dp[i]==dp[x2]*2) x2++;
            if(dp[i]==dp[x3]*3) x3++;
            if(dp[i]==dp[x5]*5) x5++;
        }
        
        return dp[n];
    }
};