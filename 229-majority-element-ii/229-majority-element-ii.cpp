class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        int x=nums[0];
        int y=-1e9-1;
        
        int cx=1;
        int cy=0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==x) cx++;
            else if(nums[i]==y) cy++;
            else if(cx==0)
            {
                x=nums[i];
                cx=1;
            }
            else if(cy==0)
            {
                y=nums[i];
                cy=1;
            }
            else 
            {
                cx--;
                cy--;
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==x)count++;
        }
        if(count>n/3) res.push_back(x);
        count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==y)count++;
        }
        if(count>n/3) res.push_back(y);
        // cout<<x<<" "<<y<<endl;
        return res;
        
    }
};