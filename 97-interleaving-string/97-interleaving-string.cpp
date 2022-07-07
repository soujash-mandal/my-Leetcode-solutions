class Solution {
public:
    int dp[101][101][201];
    
    bool fun(string &s1, string &s2, string &s3,int n1,int n2,int n3)
    {
        if(dp[n1][n2][n3]!=0)
        {
            if(dp[n1][n2][n3]==1) return true;
            return false;
        }
        
        if(n1==0 && n2==0 && n3==0) return true;
        
        
        if(n1>0 && n2>0 && n3>0 && s1[n1-1]==s3[n3-1] && s2[n2-1]==s3[n3-1])
        {
            bool res= fun(s1,s2,s3,n1-1,n2,n3-1)|fun(s1,s2,s3,n1,n2-1,n3-1);
            
            if(res) dp[n1][n2][n3]=1;
            else dp[n1][n2][n3]=-1;
            
            return res;
        }
        else if(n1>0 && n3>0 && s1[n1-1]==s3[n3-1])
        {
            bool res= fun(s1,s2,s3,n1-1,n2,n3-1);
            if(res) dp[n1][n2][n3]=1;
            else dp[n1][n2][n3]=-1;
            
            return res;
        }
        else if(n2>0 && n3>0 && s2[n2-1]==s3[n3-1])
        {
            bool res= fun(s1,s2,s3,n1,n2-1,n3-1);
            if(res) dp[n1][n2][n3]=1;
            else dp[n1][n2][n3]=-1;
            
            return res;
        }
        else
        {
            dp[n1][n2][n3]=-1;
            return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size(); 
        
        return fun(s1,s2,s3,n1,n2,n3);
    }
};