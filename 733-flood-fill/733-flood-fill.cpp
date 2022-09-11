class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        
        int mn=-65536;
        image[sr][sc]+=mn;
        
        int t=50;
        while(t--){
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=image[i][j];
                x=mn+x;
                if(x==image[sr][sc])
                {
                    if(i<m-1 && image[i+1][j]==x)
                    {
                        image[i][j]=x;
                    }
                    if(j<n-1 && image[i][j+1]==x)
                    {
                        image[i][j]=x;
                    }
                    if(i>0 && image[i-1][j]==x)
                    {
                        image[i][j]=x;
                    }
                    if(j>0 && image[i][j-1]==x)
                    {
                        image[i][j]=x;
                    }
                }
            }
        }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(image[i][j]<0)
                    image[i][j]=newColor;
            }
        }
        
        return image;
            
        
    }
};