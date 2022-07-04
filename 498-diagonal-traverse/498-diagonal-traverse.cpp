class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<int> res;
        
        for(int j=0;j<n;j++)
        {
            int a=0;
            int b=j;
            vector<int> v;
            while(a<m && b>=0)
            {
                v.push_back(mat[a][b]);
                a++;
                b--;
                
            }
            if(j%2==0)
            {
                reverse(v.begin(),v.end());
            }
            
            for(int i=0;i<v.size();i++)
            {
                res.push_back(v[i]);
            }
        }
        
        for(int i=1;i<m;i++)
        {
            int a=i;
            int b=n-1;
            vector<int> v;
            while(a<m && b>=0)
            {
                v.push_back(mat[a][b]);
                a++;
                b--;
                
            }
            if((n+i)%2!=0)
            {
                reverse(v.begin(),v.end());
            }
            
            for(int i=0;i<v.size();i++)
            {
                res.push_back(v[i]);
            }
        }
        
        return res;
    }
};