class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        int dp[target+1];
        
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            dp[i]=0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]<=i)
                {
                    if(dp[i]<=INT_MAX-dp[i-nums[j]])
                        dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};