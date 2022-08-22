class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<pair<int,int>> dp(n,{-1,-1});
        
        dp[n-1].first=1;
        
        for(int i=n-2;i>=0;i--)
        {
            dp[i].first=1;
            int nextidx=-1;
            int mx=-1;
            for(int j=i+1;j<n;j++)
            {
                if(dp[j].first>mx && nums[j]%nums[i]==0)
                {
                    mx=dp[j].first;
                    nextidx=j;
                }
            }
            if(nextidx!=-1)
            {
                dp[i].first+=mx;
                dp[i].second=nextidx;
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<dp[i].first<<" ";
        // }
        // cout<<endl;
        
        int idx=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i].first>dp[idx].first)
            {
                idx=i;
            }
        }
        
        vector<int> res;
        
        while(idx!=-1)
        {
            res.push_back(nums[idx]);
            idx=dp[idx].second;
        }
        
        
        return res;
        
    }
};