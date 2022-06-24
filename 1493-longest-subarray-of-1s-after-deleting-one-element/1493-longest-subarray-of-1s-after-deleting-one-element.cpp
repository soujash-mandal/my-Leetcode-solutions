class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool check=false;
        
        while(nums.size() && nums.back()==0)
        {
            check=true;
            nums.pop_back();
        }
        
        reverse(nums.begin(),nums.end());
        
        while(nums.size() && nums.back()==0)
        {
            check=true;
            nums.pop_back();
        }
        
        int n=nums.size();
        
        vector<int> v;
        
        int comp=1;
        int count=0;
        
        if(n==0) return 0;
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==comp)
            {
                count++;
            }
            else
            {
                v.push_back(count);
                count=1;
                comp=nums[i];
            }
        }
        v.push_back(count);
        
        int n1=v.size();
        
        if(n1==1 && check==false) return v[0]-1;
        
        for(int i=0;i<n1;i+=2)
        {
            res=max(res,v[i]);
        }
        
        for(int i=1;i<n1;i+=2)
        {
            if(v[i]==1)
            {
                res=max(res,v[i-1]+v[i+1]);
            }
        }
        
        return res;
    }
};