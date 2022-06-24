class Solution {
public:
    
    bool isValid(vector<vector<char>>& board,int a,int b, string &word,int idx,vector<vector<int>>& v)
    {
        int m=board.size();
        int n=board[0].size();
        
        int n1=word.size();
        if(idx==n1) return true;
        
        if(a<0 || a>=m || b<0 || b>=n) return false;
        if(board[a][b]!=word[idx]) return false;
        if(v[a][b]==1) return false;
        
        v[a][b]=1;
        
        bool res=(isValid(board,a+1,b,word,idx+1,v)|isValid(board,a,b+1,word,idx+1,v)|isValid(board,a-1,b,word,idx+1,v)|isValid(board,a,b-1,word,idx+1,v));
        v[a][b]=0;
        
        return res;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int>> v(m,vector<int>(n,0));   
                    if(isValid(board,i,j,word,0,v)) return true;
                }
            }
        }
        return false;
    }
};