class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int n=b.size();
        
        if(m*k>n) return -1;
        
        vector<int> day=b;
        sort(day.begin(),day.end());
        
        // for(int i=0;i<n;i++) cout<<day[i]<<" ";
        // return 0;
        
        int l=0;
        int r=n-1;
        
        int res=-1;
        
        while(r>=l)
        {
            int mid=l+(r-l)/2;
            int i=0;
            int count=0;
            
            while(i<n)
            {
                int x=k;
                while(i<n && x>0)
                {
                    if(b[i]>day[mid]) 
                    {
                        i++;
                        break;
                    }
                    // cout<<x<<" ";
                    x--;
                    i++;
                }
                
                if(x==0){
                    // cout<<i<<" "<<count<<endl;
                    count++;
                }
                
            }
            if(count>=m)
            {
                
                res=day[mid];
                // cout<<res<<endl;
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