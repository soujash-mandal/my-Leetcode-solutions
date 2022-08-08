class Solution {
public:
    
    int fun(vector<int>& nums)
    {
        vector<int> temp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(temp.size()==0)
            {
                temp.push_back(nums[i]);
            }
            else if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int lower = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
                
                temp[lower]=nums[i];         
            }
        }
        
        return temp.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return fun(nums);
    }
};