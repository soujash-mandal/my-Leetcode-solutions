class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l=1;
        int r=0;
        
        int m=q.size();
        
        for(int i=0;i<m;i++) r=max(r,q[i]);
        int res=r;
        
        while(r>=l)
        {
            int mid=l+(r-l)/2;
            
            int count=0;
            for(int i=0;i<m;i++)
            {
                count+=q[i]/mid;
                if(q[i]%mid) count++;
            }
            
            
            if(count<=n)
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