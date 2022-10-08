class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        set<int> s;
        s.insert(nums[0]);
        int res=nums[0]+nums[1]+nums[2];
        
        
        for(int i=1;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x=nums[i]+nums[j];
                auto it = s.lower_bound(target-x);
                if(it==s.end())
                {
                    it--;
                    if(abs(x+*it-target)<abs(res-target))
                    {
                        res=x+*it;
                    }
                }
                else if(it==s.begin())
                {
                    if(abs(x+*it-target)<abs(res-target))
                    {
                        res=x+*it;
                    }
                }
                else
                {
                    if(abs(x+*it-target)<abs(res-target))
                    {
                        res=x+*it;
                    }
                    it--;
                    if(abs(x+*it-target)<abs(res-target))
                    {
                        res=x+*it;
                    }
                }
            }
            s.insert(nums[i]);
        }
        
        return res;
    }
};