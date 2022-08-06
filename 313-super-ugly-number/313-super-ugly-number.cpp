class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n+1);
        
        dp[1]=1;
        
        int m=primes.size();
        
        vector<int> pos(m,1);
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=INT_MAX;
            for(int j=0;j<m;j++)
            {
                dp[i]=min(dp[i],dp[pos[j]]*1LL*primes[j]);
            }
            for(int j=0;j<m;j++)
            {
                if(dp[i]==dp[pos[j]]*1LL*primes[j])
                {
                    pos[j]++;
                }
            }
        }
        
        return dp[n];
    }
};