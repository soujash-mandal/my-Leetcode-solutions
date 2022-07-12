class Solution {
public:
    int fun(vector<int>& nums, int k) {
        int n=nums.size();
        
        int l=0;
        int res=0;
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) count++;
            
            while(count>k)
            {
                if(nums[l]==0)
                {
                    count--;
                }
                l++;
            }
            
            res=max(res,i-l+1);
        }
        
        return res;
    }
    
    int maxConsecutiveAnswers(string a, int k) {
        int n=a.size();
        vector<int> v1(n),v2(n);
        
        for(int i=0;i<n;i++)
        {
            if(a[i]=='T')
            {
                v1[i]=1;
                v2[i]=0;
            }
            else
            {
                v1[i]=0;
                v2[i]=1;
            }
        }
        
        return max(fun(v1,k),fun(v2,k));
    }
};