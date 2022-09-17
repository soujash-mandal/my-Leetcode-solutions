class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(32,0);
        int last=n-1;
        vector<int> res(n);
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            ans++;
            int x=nums[i];
            int idx=0;
            while(x)
            {
                v[idx]+=x%2;
                x/=2;
                idx++;
            }
            //***************************************************************************************
            
            bool check=true;
            while(check)
            {
                int x=nums[last];
                int idx=0;
                while(x)
                {
                    if(x%2==1 && v[idx]<=1)
                    {
                        check=false;
                        break;
                    }
                    x/=2;
                    idx++;
                }
                
                if(check)
                {
                    int x=nums[last];
                    int idx=0;
                    while(x)
                    {
                        v[idx]-=x%2;
                        x/=2;
                        idx++;
                    }
                    if(last==i) break;
                    last--;
                    ans--;
                }
                
            }
            res[i]=ans;
            
        }
        
        return res;
    }
};