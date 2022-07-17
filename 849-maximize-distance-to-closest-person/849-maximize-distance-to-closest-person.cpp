class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n=seats.size();
        
        vector<long long> l(n,1e5),r(n,1e5);
        
        if(seats[0]==1) l[0]=0;
        
        for(int i=1;i<n;i++)
        {
            l[i]=l[i-1]+1;
            if(seats[i]==1) l[i]=0;
        }
        
        if(seats[n-1]==1) r[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            r[i]=r[i+1]+1;
            if(seats[i]==1) r[i]=0;
        }
        
        long long res=1;
        
        for(int i=0;i<n;i++)
        {
            // cout<<r[i]<<" ";
            res=max(res,min(l[i],r[i]));
        }
        
        return res;
    }
};