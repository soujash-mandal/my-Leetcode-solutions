class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        
        int n=w.size();
        
        int l=0;
        int r=0;
        
        for(int i=0;i<n;i++)
        {
            l=max(l,w[i]);
            r+=w[i];
        }
        
        int res=r;
        
        while(r>=l)
        {
            int mid=l+(r-l)/2;
            
            int x=mid;
            int count=1;
            
            for(int i=0;i<n;i++)
            {
                if(x>=w[i])
                {
                    x-=w[i];
                }
                else
                {
                    x=mid-w[i];
                    count++;
                }
            }
            
            if(count<=d)
            {
                res=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        
        return res;
    }
};