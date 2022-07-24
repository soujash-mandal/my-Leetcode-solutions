class Solution {
public:
    vector<vector<int>> dp;
    
    int fun(vector<vector<int>>& pairs,int idx,int last)
    {
        if(idx==pairs.size()) return 0;
        if(dp[idx][last+1]!=-1) return dp[idx][last+1];
        
        int res=fun(pairs,idx+1,last);
        if(last==-1 || pairs[idx][0]>pairs[last][1])
        {
            res=max(res,1+fun(pairs,idx+1,idx));
        }
        
        return dp[idx][last+1]=res;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        
        int n=pairs.size();
        vector<vector<int>> temp(n,vector<int>(n+10,-1));
        dp=temp;
        return fun(pairs,0,-1);
    }
};