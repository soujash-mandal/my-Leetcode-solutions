class Solution {
public:
    bool possible(int n,vector<int>& ranges)
    {
        vector<int> v(n+2,0);
        for(int i=0;i<=n;i++)
        {
            if(ranges[i])
            {
                int l=max(0,i-ranges[i]);
                int r=min(n,i+ranges[i]);
                
                v[l]++;
                v[r+1]--;
            }
        }
        
        
        if(v[0]==0) return false;
        for(int i=1;i<=n;i++)
        {
            v[i]+=v[i-1];
            if(v[i]<=0) return false;
        }
        
        return true;
    }
    
    
    int minTaps(int n, vector<int>& ranges) {
        
        if(!possible(n,ranges)) return -1;
        
        vector<int> v(n+1,0);
        
        
        for(int i=0;i<=n;i++)
        {
            int l=max(0,i-ranges[i]);
            int r=min(i+ranges[i],n);
            
            v[l]=max(v[l],r);
        }
        
        // for(int i=0;i<=n;i++) cout<<v[i]<<" ";
        
        int range=0;
        int res=0;
        int idx=0;
        
        while(idx<=n)
        {
            res++;
            int temp=range;
            
            while(idx<=range)
            {
                temp=max(temp,v[idx]);
                idx++;
            }
            if(range==n) return res-1;
            range=temp;
        }
        
        return res;
    }
};