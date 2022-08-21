class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int x=1;
        int match=nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==match) x++;
            else x--;
            
            if(x<0)
            {
                match=nums[i];
                x=1;
            }
        }
        
        return match;
    }
};