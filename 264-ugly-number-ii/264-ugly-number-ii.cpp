class Solution {
public:
    
    int nthUglyNumber(int n) {
        // cout<<log(INT_MAX)/log(5);
        
        set<long long> s;
        long long ex2=1;
        for(int i=0;i<=32;i++)
        {
            long long ex3=1;
            for(int j=0;j<=20;j++)
            {
                long long ex5=1;
                for(int k=0;k<=14;k++)
                {
                    long long x=ex3*ex2;
                    if(x>=INT_MAX) break;
                    x*=ex5;
                    if(x>=INT_MAX) break;
                    
                    s.insert(x);
                    ex5*=5;
                }
                ex3*=3;
                if(ex3>=INT_MAX) break;
            }
            ex2*=2;
            if(ex2>=INT_MAX) break;
        }
        
        
        int count=0;
        for(auto it=s.begin();it!=s.end();it++)
        {
            count++;
            if(count==n) return *it;
        }
        
        return 0;
    }
};