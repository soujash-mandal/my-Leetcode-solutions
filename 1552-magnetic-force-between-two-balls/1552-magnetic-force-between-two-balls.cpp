class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        int n=p.size();
        sort(p.begin(),p.end());
        
        int l=1;
        int r=p[n-1]-p[0];
        
        int res=1;
        
        while(r>=l)
        {
            int mid=l+(r-l)/2;
            // cout<<mid<<" ";
            
            int count=0;
            int start=0;
            for(int i=1;i<n;i++)
            {
                if(p[i]>=p[start]+mid)
                {
                    count++;
                    start=i;
                }  
            }
            if(count>=m-1)
            {
                res=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        
        return res;
    }
};