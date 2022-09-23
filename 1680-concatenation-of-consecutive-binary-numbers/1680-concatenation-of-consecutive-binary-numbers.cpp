vector<int> dp(100010,-1);
class Solution {
public:
    vector<int> decToBin(int n)
    {
        vector<int> res;
        while(n)
        {
            res.push_back(n%2);
            n/=2;
        }
        return res;
    }
    int m=1e9+7;
    
    int mod_mul(int a,int b)
    {
        return ((a%m)*(b%m))%m;
    }
    
    int mod_add(int a,int b)
    {
        return ((a%m)+(b%m))%m;
    }
    
    
    
    int concatenatedBinary(int n) {
        if(dp[n]!=-1) return dp[n];
        int res=0;
        
        for(int i=1;i<=100000;i++)
        {
            vector<int> val=decToBin(i);
            reverse(val.begin(),val.end());
            
            for(int j=0;j<val.size();j++)
            {
                res=mod_mul(res,2);
                res=mod_add(res,val[j]);
            }
            dp[i]=res;
        }
        return dp[n];
    }
};