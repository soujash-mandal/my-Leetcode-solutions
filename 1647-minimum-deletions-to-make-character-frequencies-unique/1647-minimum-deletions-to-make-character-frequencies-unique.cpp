class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a']++;
        }
        sort(v.begin(),v.end());
        set<int> s1;
        int x=0;
        int res=0;
        
        for(int i=0;i<26;i++)
        {
            if(v[i]!=0)
            {
                if(s1.find(v[i])==s1.end())
                {
                    s1.insert(v[i]);
                }
                else
                {
                    int x=1;
                    while(v[i]-x>0 && s1.find(v[i]-x)!=s1.end())
                    {
                        x++;
                    }
                    if(v[i]-x!=0) s1.insert(v[i]-x);
                    res+=x;
                }
            }
        }
        
        return res;
    }
};