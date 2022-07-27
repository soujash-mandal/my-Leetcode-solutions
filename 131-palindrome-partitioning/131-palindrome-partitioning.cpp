class Solution {
public:
    bool ispal(string str)
    {
        for(int i=0;i<str.size()/2;i++)
        {
            if(str[i]!=str[str.size()-i-1]) return false;
        }
        return true;
    }
    
    vector<vector<string>> res;
    
    void fun(string s,int idx,string curr,vector<string> v)
    {
        if(idx==s.size())
        {
            if(curr=="") res.push_back(v);
            return;
        }
        curr+=s[idx];
        fun(s,idx+1,curr,v);
        if(ispal(curr))
        {
            v.push_back(curr);
            fun(s,idx+1,"",v);
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        fun(s,0,"",v);
        return res;
    }
};