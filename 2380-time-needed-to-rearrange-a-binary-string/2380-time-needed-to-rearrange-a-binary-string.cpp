class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.size();
        bool check=true;
        int t=0;
        while(check)
        {
            check=false;
        
            for(int i=1;i<n;i++)
            {
                if(s[i]=='1' && s[i-1]=='0')
                {
                    s[i]='0';
                    s[i-1]='1';
                    i++;
                    check=true;
                }
            }
            if(check) t++;
            
        }
        
        return t;
    }
};