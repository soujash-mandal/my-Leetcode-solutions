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
    
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<vector<int>> v(26,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            v[s[i]-'A'][i]=1;
        }
        
        int res=0;
        for(int i=0;i<26;i++)
        {
            res=max(res,longestOnes(v[i],k));
        }
        
        return res;
    }
};