class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        
        v.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>v.back())
            {
                v.push_back(nums[i]);
                if(v.size()>=3) return true;
                continue;
            }
            int idx=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
            v[idx]=nums[i];
        }
        
        return false;
    }
};