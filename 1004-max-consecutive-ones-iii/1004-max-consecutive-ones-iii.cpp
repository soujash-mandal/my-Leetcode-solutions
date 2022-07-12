class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
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
};