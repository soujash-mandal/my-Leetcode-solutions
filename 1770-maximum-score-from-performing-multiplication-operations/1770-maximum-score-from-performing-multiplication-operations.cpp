class Solution {
public:
//     int fun(int l,int r,vector<int>& nums, vector<int>& mul,int idx,int m,vector<vector<int>>& dp)
//     {
//         if(idx==m) return 0;
//         int n=nums.size();
//         if(dp[l][n-1-r]!=-1) return dp[l][n-1-r];
//         int res1=mul[idx]*nums[l]+fun(l+1,r,nums,mul,idx+1,m,dp);
//         int res2=mul[idx]*nums[r]+fun(l,r-1,nums,mul,idx+1,m,dp);
        
//         return dp[l][n-1-r]=max(res1,res2);
//     }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n=nums.size();
        int m=mul.size();
        vector<vector<int>> dp(m+10,vector<int> (m+10,-1));
        dp[m][0]=0;
        for(int i=m-1;i>=0;i--)
        {
            dp[i][m-i]=0;
            for(int j=m-1-i;j>=0;j--)
            {
                dp[i][j]=max(mul[i+j]*nums[i]+dp[i+1][j],mul[i+j]*nums[n-1-j]+dp[i][j+1]);
            }
        }
        
        // for(int i=0;i<m+1;i++)
        // {
        //     for(int j=0;j<m+1;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[0][0];
        
        // return fun(0,n-1,nums,mul,0,m,dp);
    }
};