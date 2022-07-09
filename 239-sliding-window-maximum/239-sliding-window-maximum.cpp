class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        
        set<int> s;
        map<int,int> mp;
        
        for(int i=0;i<k;i++)
        {
            s.insert(nums[i]);
            mp[nums[i]]++;
        }
        
        auto last=s.end();
        last--;
        
        vector<int> res;
        res.push_back(*last);
        
        for(int i=k;i<n;i++)
        {
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0) s.erase(nums[i-k]);
            s.insert(nums[i]);
            mp[nums[i]]++;
            
            auto it=s.end();
            it--;
            
            res.push_back(*it);
        }
        
        return res;
    }
};