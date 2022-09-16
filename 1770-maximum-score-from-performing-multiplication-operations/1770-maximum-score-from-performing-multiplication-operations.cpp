class Solution {
public: 
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
        return dp[0][0];
    }
};