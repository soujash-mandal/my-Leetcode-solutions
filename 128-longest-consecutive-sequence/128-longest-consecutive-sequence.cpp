class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> setmap;
        int n=nums.size();
        if(n==0 || n==1) return n;
        
        for(int i=0;i<n;i++)
        {
            setmap.insert(nums[i]);
        }
        
        auto it=setmap.begin();
        int x=*it;
        it++;
        
        int res=1,count=1;
        
        while(it!=setmap.end())
        {
            if(*it==x+1)
            {
                count++;
                res=max(res,count);
            }
            else
            {
                count=1;
            }
            x=*it;
            it++;
        }
        return res;
    }
};