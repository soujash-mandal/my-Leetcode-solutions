class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        
        dp[0][nums[0]%3]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            vector<int> v(3,0);
            v=dp[i-1];
            
            int a=dp[i-1][0]+nums[i];
            int b=dp[i-1][1]+nums[i];
            int c=dp[i-1][2]+nums[i];
            
            v[a%3]=max(v[a%3],a);
            v[b%3]=max(v[b%3],b);
            v[c%3]=max(v[c%3],c);
            
            dp[i]=v;
        }
        
        return dp[n-1][0];
    }
};