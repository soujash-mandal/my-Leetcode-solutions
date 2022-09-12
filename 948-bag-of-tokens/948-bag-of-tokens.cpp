class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        
        int res=0;
        int count=0;
        
        int l=0;
        int r=n-1;
        
        while(r>=l)
        {
            if(power>=tokens[l])
            {
                count++;
                power-=tokens[l];
                res=max(res,count);
                l++;
            }
            else
            {
                count--;
                power+=tokens[r];
                r--;
                if(count<0) break;
            }
        }
        
        return res;
    }
};