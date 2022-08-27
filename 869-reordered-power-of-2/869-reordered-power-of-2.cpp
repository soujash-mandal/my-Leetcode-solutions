class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> v;
        
        for(int i=1;i<=1e9;i*=2)
        {
            string x=to_string(i);
            sort(x.begin(),x.end());
            v.push_back(x);
        }
        
        string res=to_string(n);
        sort(res.begin(),res.end());
        
        for(int i=0;i<v.size();i++)
        {
            if(res==v[i]) return true;
        }
        return false;
    }
};