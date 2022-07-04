class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<int> res;
        int a=0;
        
        while(res.size()<m*n){
            
            for(int j=a;j<n-a;j++)
            {
                res.push_back(mat[a][j]);
            }
            if(res.size()>=m*n) break;
            for(int i=a+1;i<m-a;i++)
            {
                res.push_back(mat[i][n-1-a]);
            }
            if(res.size()>=m*n) break;
            for(int j=n-2-a;j>=a;j--)
            {
                res.push_back(mat[m-1-a][j]);
            }
            if(res.size()>=m*n) break;
            for(int i=m-2-a;i>a;i--)
            {
                res.push_back(mat[i][a]);
            }
        
            a++;
        
        }
        
        return res;
    }
};