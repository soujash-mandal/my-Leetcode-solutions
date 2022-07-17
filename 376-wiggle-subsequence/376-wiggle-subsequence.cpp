class Solution {
public:
    
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1]) v.push_back(nums[i]);
        }
        
        
        n=v.size();
        int res=1;
        
        if(v.size()>=2) res=2;
        
        for(int i=1;i<n-1;i++)
        {
            if(v[i-1]>v[i] && v[i]<v[i+1]) res++;
            if(v[i-1]<v[i] && v[i]>v[i+1]) res++;
        }
        
        
        return res;
    }
};