class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int l=0;
        int r=0;
        set<int> s;
        map<int,int> mp;
        
        s.insert(nums[0]);
        mp[nums[0]]++;
        
        vector<int> dp(n);
        dp[0]=nums[0];
        r++;
        
        for(int i=1;i<n;i++)
        {
            if(r-l>k)
            {
                mp[dp[l]]--;
                if(mp[dp[l]]==0) s.erase(dp[l]);
                l++;
            }
            auto it=s.end();
            it--;
            dp[i]=*it+nums[i];
            s.insert(dp[i]);
            mp[dp[i]]++;
            r++;
        }
        
        for(int i=0;i<n;i++)cout<<dp[i]<<" ";
        
        return dp[n-1];
    }
};