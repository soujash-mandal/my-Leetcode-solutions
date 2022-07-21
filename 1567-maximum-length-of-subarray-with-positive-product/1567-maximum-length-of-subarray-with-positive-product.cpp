class Solution {
public:
    int fun(vector<int>& nums,int a,int b)
    {
        int ans=0;
        int res=1;
        for(int i=a;i<=b;i++)
        {
            res*=nums[i];
            if(res>0) ans=max(ans,i-a+1);
            // cout<<ans<<endl;
        }
        
        res=1;
        for(int i=b;i>=a;i--)
        {
            res*=nums[i];
            if(res>0) ans=max(ans,b-i+1);
        }
        
        return ans;
        
    }
    int getMaxLen(vector<int>& nums) {
        int idx=0;
        int res=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) nums[i]=1;
            if(nums[i]<0) nums[i]=-1;
        }
        
        while(idx<n)
        {
            int a=idx;
            while(idx<n && nums[idx]==0)
            {
                idx++;
                a++;
            }
            int b=a;
            while(idx<n && nums[idx]!=0)
            {
                idx++;
                b++;
            }
            
            if(a!=n)
            {
                // cout<<a<<" "<<b<<endl;
                res=max(res,fun(nums,a,b-1));
            }
            
        }
        
        
        return res;
    }
};