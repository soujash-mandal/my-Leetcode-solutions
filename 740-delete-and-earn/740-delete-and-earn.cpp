class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(1e4+10,0);
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            dp[nums[i]]+=nums[i];
        }
        
        // for(int i=0;i<=4;i++) cout<<dp[i]<<" ";
        
        for(int i=2;i<=1e4;i++)
        {
            dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
        }
        
        return dp[1e4];
    }
};