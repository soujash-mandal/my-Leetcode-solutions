class Solution {
public:
    int m=1e9+7;
    
    vector<vector<int>> dp;
    
    int fun(int n1,int n2)
    {
        if(n1<0 || n2<0) return 0;
        if( n1==n2 && n1==0) return 1;
        
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        
        int res=0;
        if(n1==n2)
        {
            res+=fun(n1-1,n2-1);
            res%=m;
            res+=fun(n1-2,n2-1);
            res%=m;
            res+=fun(n1-1,n2-2);
            res%=m;
            // res+=fun(n1-2,n2);
            res+=fun(n1,n2-2);
            res%=m;
        }
        
        else if(n1==n2+1)
        {
            res+=fun(n1-2,n2-1);
            res%=m;
            res+=fun(n1-2,n2);
            res%=m;
            // res+=fun(n1,n2-2);
        }
        else if(n2==n1+1)
        {
            res+=fun(n1-1,n2-2);
            res%=m;
            // res+=fun(n1-2,n2);
            res+=fun(n1,n2-2);
            res%=m;
        }
        
        else if(n1>n2)
        {
            res+=fun(n1-2,n2);
            res%=m;
            
        }
        else
        {
            res+=fun(n1,n2-2);
            res%=m;
        }
        
        return dp[n1][n2]=res;
        
    }
    int numTilings(int n) {
        vector<vector<int>> temp(n+1,vector<int>(n+1,-1));
        dp=temp;
        return fun(n,n);
    }
};