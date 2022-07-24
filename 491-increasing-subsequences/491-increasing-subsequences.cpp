class Solution {
public:
    set<vector<int>> res;
    
    void fun(vector<int>& nums,int idx,int last,vector<int> v)
    {
        if(idx==nums.size())
        {
            if(v.size()<=1) return;
            res.insert(v);
            return;
        }
        fun(nums,idx+1,last,v);
        if(last==-1 || nums[idx]>=nums[last])
        {
            v.push_back(nums[idx]);
            fun(nums,idx+1,idx,v);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        fun(nums,0,-1,v);
        
        vector<vector<int>> ans(res.begin(),res.end());
        
        return ans;
    }
};