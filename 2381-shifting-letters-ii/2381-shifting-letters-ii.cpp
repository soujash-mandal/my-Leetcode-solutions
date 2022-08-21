class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<long long> a(n+1,0);
        
        for(int i=0;i<shifts.size();i++)
        {
            if(shifts[i][2]==1)
            {
                a[shifts[i][0]]++;
                a[shifts[i][1]+1]--;
            }
            else
            {
                a[shifts[i][0]]--;
                a[shifts[i][1]+1]++;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            a[i]+=a[i-1];
        }
//         for(int i=0;i<n;i++) cout<<a[i]<<" ";
//         cout<<endl;
        
        for(int i=0;i<n;i++)
        {
            s[i]='a'+((s[i]-'a')+(2600000+a[i]))%26;
        }
        
        return s;
        
        
    }
};