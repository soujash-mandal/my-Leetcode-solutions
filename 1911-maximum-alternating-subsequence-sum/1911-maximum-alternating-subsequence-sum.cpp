class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> up,down;
        
        int n=nums.size();
        
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1]) v.push_back(nums[i]);
        }
        
        nums=v;
        n=nums.size();
        
        if(n>1 && nums[0]>nums[1]) up.push_back(nums[0]);
        if(n>1 && nums[n-1]>nums[n-2]) up.push_back(nums[n-1]);
        
        for(int i=1;i<n-1;i++)
        {
            if(nums[i-1]>nums[i] && nums[i]<nums[i+1])
            {
                down.push_back(nums[i]);
            }
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1])
            {
                up.push_back(nums[i]);
            }
        }
        long long res=nums[0];
        
        long long sum=0;
        for(int i=0;i<up.size();i++)sum+=up[i];
        for(int i=0;i<down.size();i++) sum-=down[i];
        
        
        return max(sum,res);
    }
};