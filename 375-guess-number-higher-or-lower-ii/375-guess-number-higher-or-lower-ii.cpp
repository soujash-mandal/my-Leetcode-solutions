class Solution {
public:
    vector<vector<int>> dp;
    
    int fun(int start,int end)
    {
        if(start>=end) return 0;
        
        if(dp[start][end]!=-1) return dp[start][end];
        
        int res=INT_MAX;
        
        for(int i=start;i<=end;i++)
        {
            res=min(res,i+max(fun(start,i-1),fun(i+1,end)));
        }
        
        return dp[start][end]=res;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> temp(n+1,vector<int>(n+1,-1));
        dp=temp;
        return fun(1,n);
    }
};