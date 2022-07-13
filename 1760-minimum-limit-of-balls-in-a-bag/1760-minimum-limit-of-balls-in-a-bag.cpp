class Solution {
public:
    int minimumSize(vector<int>& nums, int op) {
        int l=1;
        int r=1;
        int n=nums.size();
        for(int i=0;i<n;i++) r=max(r,nums[i]);
        int res=r;
        
        while(r>=l)
        {
            int mid=l+(r-l)/2;
            int count=0;
            for(int i=0;i<n;i++)
            {
                count+=nums[i]/mid;
                if(nums[i]%mid) count++;
            }
            
            if(count<=n+op)
            {
                res=mid;
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