class Solution {
public:
    int mod=1e9+7;
    
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<pair<long long,long long>>> dp(m,vector<pair<long long,long long>>(n));
        
        dp[m-1][n-1].first=grid[m-1][n-1];
        dp[m-1][n-1].second=grid[m-1][n-1];
        
        for(int i=m-2;i>=0;i--)
        {
            dp[i][n-1].first=((dp[i+1][n-1].first)*1LL*(grid[i][n-1]));
            dp[i][n-1].second=dp[i][n-1].first;
            
        }
        
        for(int j=n-2;j>=0;j--)
        {
            dp[m-1][j].first=((dp[m-1][j+1].first)*1LL*(grid[m-1][j]));
            dp[m-1][j].second=dp[m-1][j].first;
        }
        
        // return 0;
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                long long mx=max(dp[i][j+1].first,dp[i+1][j].first);
                long long mn=min(dp[i][j+1].second,dp[i+1][j].second);
                
                mx=((mx)*1LL*(grid[i][j]));
                mn=((mn)*1LL*(grid[i][j]));
                
                dp[i][j].first=max(mx,mn);
                dp[i][j].second=min(mx,mn);
                
            }
        }
        
        long long res=dp[0][0].first;
        
        
        if(res<0) return -1;
        
        return res%mod;
        
        
        
    }
};