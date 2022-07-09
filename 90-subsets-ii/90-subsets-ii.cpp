class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        
        set<vector<int>> s;
        // s.insert({});
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            vector<vector<int>> v=res;
            
            for(int j=0;j<v.size();j++)
            {
                vector<int> temp=v[j];
                temp.push_back(nums[i]);
                sort(temp.begin(),temp.end());
                res.push_back(temp);
                s.insert(temp);
            }
            vector<vector<int>> v2(s.begin(),s.end());
            v2.push_back({});
            res=v2;
        }
        
        
        return res;
              
    }
};