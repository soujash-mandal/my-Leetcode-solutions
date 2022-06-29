class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        vector<int> l(n),r(n);
        
        int ans=0;
        
        int maxnum=INT_MIN;
        
        for(int i=0;i<n;i++)
        {  
            maxnum=max(maxnum,nums[i]);
            
            sum+=nums[i];
            
            ans=max(ans,sum);
            
            if(sum<0)
            {
                sum=0;
            }
            l[i]=sum;
           
        }
        
        sum=0;
        
        for(int i=n-1;i>=0;i--)
        {
            sum+=nums[i];
            if(sum<0) sum=0;
            r[i]=sum;
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            int res=0;
            
            if(i>0) res+=l[i-1];
            if(i<n-1) res+=r[i+1];
            
            ans=max(res,ans);
            
        }
        
        if(maxnum<=0) return maxnum;
        
        return ans;
    }
};