class Solution {
public:
    bool canConstruct(string s1, string s2) {
        map<char,int> mp1,mp2; 
        
        for(int i=0;i<s1.size();i++) mp1[s1[i]]++;
        for(int i=0;i<s2.size();i++) mp2[s2[i]]++;
        
        bool check=true;
        for(auto it:mp1)
        {
            if(mp2[it.first]<it.second)
            {
                check=false;
                break;
            }
        }
        
        return check;
    }
};