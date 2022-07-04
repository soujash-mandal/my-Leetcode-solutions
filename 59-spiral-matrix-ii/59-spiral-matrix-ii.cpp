class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int c=1;
        int a=0;
        
        while(c<=n*n)
        {
            for(int j=a;j<n-a;j++)
            {
                res[a][j]=c;
                c++;
            }
            for(int i=a+1;i<n-a;i++)
            {
                res[i][n-1-a]=c;
                c++;
            }
            for(int j=n-2-a;j>=a;j--)
            {
                res[n-1-a][j]=c;
                c++;
            }
            for(int i=n-2-a;i>a;i--)
            {
                res[i][a]=c;
                c++;
            }
            a++;
        }
        
        return res;
    }
};