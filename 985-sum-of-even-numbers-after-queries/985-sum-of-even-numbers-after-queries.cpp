class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                sum+=nums[i];
            }
        }
        
        vector<int> res;
        n=q.size();
        
        for(int i=0;i<n;i++)
        {
            int idx=q[i][1];
            int x=q[i][0];
            
            if(nums[idx]%2==0)
            {
                if((nums[idx]+x)%2==0)
                {
                    sum+=x;
                }
                else
                {
                    sum-=nums[idx];
                }
                
                nums[idx]+=x;
            }
            else
            {
                nums[idx]+=x;
                if(nums[idx]%2==0)
                {
                    sum+=nums[idx];
                }
                
            }
            
            res.push_back(sum);
        }
        
        return res;
    }
};