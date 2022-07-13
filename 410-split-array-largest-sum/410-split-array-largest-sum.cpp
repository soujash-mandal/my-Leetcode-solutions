class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l=0;
        int r=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            l=max(l,nums[i]);
            r+=nums[i];
        }
        
        int res=r;
        
        while(r>=l)
        {
            int mid=l+(r-l)/2;
            int x=mid;
            int count=1;
            
            for(int i=0;i<n;i++)
            {
                if(x>=nums[i])
                {
                    x-=nums[i];
                }
                else
                {
                    x=mid-nums[i];
                    count++;
                }
            }
            
            if(count<=m)
            {
                res=mid;
                // cout<<res<<endl;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return res;
    }
};