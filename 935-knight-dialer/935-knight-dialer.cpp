class Solution {
public:
    int knightDialer(int n) {
        vector<vector<long long>> dp(n,vector<long long>(10,1));
        
        int m=1e9+7;
        
        for(int i=1;i<n;i++)
        {
            dp[i][0]=(dp[i-1][6]+dp[i-1][4])%m;
            dp[i][1]=(dp[i-1][6]+dp[i-1][8])%m;
            dp[i][2]=(dp[i-1][7]+dp[i-1][9])%m;
            dp[i][3]=(dp[i-1][8]+dp[i-1][4])%m;
            dp[i][4]=(dp[i-1][0]+dp[i-1][3]+dp[i-1][9])%m;
            dp[i][5]=0;
            dp[i][6]=(dp[i-1][0]+dp[i-1][7]+dp[i-1][1])%m;
            dp[i][7]=(dp[i-1][6]+dp[i-1][2])%m;
            dp[i][8]=(dp[i-1][1]+dp[i-1][3])%m;
            dp[i][9]=(dp[i-1][2]+dp[i-1][4])%m;
        }
        
        int res=0;
        
        for(int i=0;i<10;i++)
        {
            res+=dp[n-1][i];
            res%=m;
        }
        
        return res;
    }
};