class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        
        vector<string> res;
        
        for(int i=2;i<=n;i++)
        {
            string temp="1/";
            temp+=to_string(i);
            
            res.push_back(temp);
            for(int j=2;j<i;j++)
            {
                if(__gcd(i,j)==1)
                {
                    temp="";
                    temp+=to_string(j);
                    temp+='/';
                    temp+=to_string(i);
                    res.push_back(temp);
                }
            }
        }
        
        return res;
    }
};