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
        
        // 5 5 5 4 4 4 6 6 6 -> 5 4 6
        // converting nums vector like this
        
        
        nums=v;
        n=nums.size();
        
        if(n==1) return nums[0];// if only one element exist return that
        
        
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
        // saved every peak in up vector and down one in down vector
        // 1 2 3 6 3 2 7 8 9 5 2 1 4
        // 6 2 9 1 4
        // this is my maximum alternating sum subsequence
        // up  -> 6 9 4
        // down-> 2 1
        
        // ans= sum(up)-sum(down);
        
        
        
        long long res=0;
        for(int i=0;i<up.size();i++)res+=up[i];
        for(int i=0;i<down.size();i++) res-=down[i];
        
        
        return res;
    }
};