class Solution {
public:
    
    int sum=0;
    bool fun(vector<int>& matchsticks,int a,int b,int c,int d,int n)
    {
        if(n==0 && a==b && a==c && a==d) return true;
        if(n==0) return false;
        
        if(a>sum || b>sum || c>sum || d>sum) return false;
        
        
        
        bool res=false;
        res=res|fun(matchsticks,a+matchsticks[n-1],b,c,d,n-1);
        if(res) return true;
        
        if(b!=a) res=res|fun(matchsticks,a,b+matchsticks[n-1],c,d,n-1);
        if(res) return true;
        
        
        if(c!=a && c!=b) res=res|fun(matchsticks,a,b,c+matchsticks[n-1],d,n-1);
        if(res) return true;
        
        if(d!=c && d!=a && d!=b)res=res|fun(matchsticks,a,b,c,d+matchsticks[n-1],n-1);
        
        if(res) return true;
        
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int a=0,b=0,c=0,d=0;
        vector<int> side(4,0);
        int n=matchsticks.size();
        // sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        for(int i=0;i<n;i++)
        {
            sum+=matchsticks[i];
        }
        
        if(sum%4!=0) return false;
        
        sum/=4;
        return fun(matchsticks,a,b,c,d,n);
    }
};