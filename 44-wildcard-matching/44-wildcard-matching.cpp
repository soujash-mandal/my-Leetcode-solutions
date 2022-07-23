class Solution {
public:
    
    vector<vector<int>> dp;
    int star=0;
    bool fun(string s,string p,int is,int ip)
    {
        int ns=s.size();
        int np=p.size();
        
        if(is>ns || ip>np) return false;
        
        if(dp[is][ip]!=-1) return dp[is][ip];
        
        if(is==ns)
        {
            int idx=ip;
            while(ip<np)
            {
                if(p[ip]!='*')return false;
                ip++;
            }
            for(int i=idx;i<=np;i++)
            {
                dp[is][i]=true;
            }
            return true;
        }
        
        if(is>=ns || ip>=np) return false;
        
        if(p[ip]>='a' && p[ip]<='z'){
            if(p[ip]!=s[is]) return dp[is][ip]=false;
            else return dp[is][ip]=fun(s,p,is+1,ip+1);
        }
        
        if(p[ip]=='?') return dp[is][ip]=fun(s,p,is+1,ip+1);
        
        
        for(int i=is;i<=ns;i++)
        {
            if(ns-i<np-ip-star) break;
            bool x=fun(s,p,i,ip+1);
            dp[i][ip+1]=x;
            if(x) return dp[is][ip]=true;
                
        }
        
        return dp[is][ip]=false;
    }
    bool isMatch(string s, string p) {
        if(s==p) return true;
        
        if(p.size()==0) return false;
        vector<vector<int>> temp(s.size()+1,vector<int>(p.size()+1,-1));
        dp=temp;
        
        string str="";
        str+=p[0];
        for(int i=1;i<p.size();i++)
        {
            if(p[i]=='*' && p[i-1]=='*') continue;
            str+=p[i];
        }
        p=str;
        // int star=0;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]=='*') star++;
        }
        return fun(s,p,0,0);
    }
};