class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        map<char,int> mp1,mp2,rmp1,rmp2;
        for(int i=0;i<n;i++)
        {
                if(i%2==0)rmp1[s[i]]++;
                else rmp2[s[i]]++;
        }
        if(n%2==0)
        {   
            return min(rmp1['0']+rmp2['1'],rmp1['1']+rmp2['0']);
        }
        else
        {
            int res=min(rmp1['0']+rmp2['1'],rmp1['1']+rmp2['0']);
            for(int i=0;i<n;i++)
            {
                if(i%2==0)
                {
                    mp1[s[i]]++;
                    rmp1[s[i]]--;
                    
                    res=min(res,mp1['0']+rmp2['0']+mp2['1']+rmp1['1']);
                    res=min(res,mp1['1']+rmp2['1']+mp2['0']+rmp1['0']);
                }
                else
                {
                    mp2[s[i]]++;
                    rmp2[s[i]]--;
                    
                    res=min(res,mp1['0']+rmp2['0']+mp2['1']+rmp1['1']);
                    res=min(res,mp1['1']+rmp2['1']+mp2['0']+rmp1['0']);
                }
            }
            return res;
        }
        
    }
};