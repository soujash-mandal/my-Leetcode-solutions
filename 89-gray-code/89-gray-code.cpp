class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        
        res.push_back(0);
        res.push_back(1);
        
        int p=1;
        
        for(int i=1;i<n;i++)
        {
            p*=2;
            int x=res.size();
            for(int j=x-1;j>=0;j--)
            {
                res.push_back(res[j]+p);
            }
        }
        
        return res;
    }
};