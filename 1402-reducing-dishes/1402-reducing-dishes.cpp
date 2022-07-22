class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<set<int>> s(n);
        
        sort(sat.begin(),sat.end());
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=sat[i];
        }
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                auto it=s[j-1].end();
                it--;
                dp[i][j]=*it+(j+1)*sat[i];
                
            }
            for(int j=0;j<=i;j++)
            {
                res=max(res,dp[i][j]);
                // s[j].insert(max(((j+1)*sat[i]),(dp[i][j])));
                s[j].insert(dp[i][j]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        
        return res;
    }
};