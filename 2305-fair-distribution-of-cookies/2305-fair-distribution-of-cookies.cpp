class Solution {
public:
    int fun(vector<int>& c,int idx,int k,vector<int>& v)
    {
        if(idx==c.size())
        {
            int x=0;
            for(int i=0;i<k;i++)
            {
                x=max(x,v[i]);
            }
            return x;
        }
        int res=INT_MAX;
        
        for(int i=0;i<k;i++)
        {
            v[i]+=c[idx];
            res=min(res,fun(c,idx+1,k,v));
            v[i]-=c[idx];
        }
        
        return res;
    }
    
    int distributeCookies(vector<int>& c, int k) {
        vector<int> v(k,0);
        return fun(c,0,k,v);
        
    }
};