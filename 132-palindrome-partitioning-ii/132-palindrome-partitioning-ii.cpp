class Solution {
public:
    
    bool ispal(string &str,int start,int end)
    {
        while(end>start)
        {
            if(str[end]!=str[start]) return false;
            end--;
            start++;
        }
        return true;
    }
    
    vector<int> dp;
    
    int fun(string &s,int idx,int start,int end)
    {
        if(idx==s.size())
        {
            if(start==end) return 0;
            else return 1e5;
        }
        // curr+=s[idx];
        
        if(dp[start]!=-1) return dp[start];
        
        int res=1e5;
        
        if(ispal(s,start,end))
        {
            res=min(res,1+fun(s,idx+1,idx+1,idx+1));
        }
        
        res=min(res,fun(s,idx+1,start,idx+1));
        
        if(res>=1e5) return dp[start]=1e5;
        return dp[start]=res;
        
    }
    
    int minCut(string s) {
        vector<int> temp(s.size(),-1);
        dp=temp;
        return fun(s,0,0,0)-1;
    }
};