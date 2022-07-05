class Solution {
public:
    string decodeCiphertext(string e, int rows) {
        string res="";
        int n=e.size();
        
        int x=n/rows;
        
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<rows;j++)
            {
                int idx=i+x*j+j;
                if(idx<n)
                {
                    res+=e[idx];
                }
            }
        }
        
        while(res.size() && res.back()==' ') res.pop_back();
        
        return res;
    }
};