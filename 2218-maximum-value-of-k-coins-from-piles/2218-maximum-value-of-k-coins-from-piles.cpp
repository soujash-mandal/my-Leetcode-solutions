class Solution {
public:
    vector<vector<int>> dp;
    
    int fun(vector<vector<int>>& piles,int idx,int k,bool check)
    {
        int n=piles.size();
        
        if(idx>=n) return 0;
        if(k<0) return 0;
        
        if(check && dp[idx][k]!=-1) return dp[idx][k];
        
        int res=fun(piles,idx+1,k,true);
        
        if(piles[idx].size()>0)
        {
            int x=piles[idx].back();
            
            piles[idx].pop_back();
            res=max(res,x+fun(piles,idx+1,k-1,true));
            res=max(res,x+fun(piles,idx,k-1,false));
            piles[idx].push_back(x);
        }
        if(check)
        {
            dp[idx][k]=res;
        }
        return res;
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int m=piles.size();
        vector<vector<int>> temp(m,vector<int>(k,-1));
        dp=temp;
        for(int i=0;i<m;i++)
        {
            reverse(piles[i].begin(),piles[i].end());
        }
        
        // return 0;
        
        return fun(piles,0,k-1,true);
    }
};