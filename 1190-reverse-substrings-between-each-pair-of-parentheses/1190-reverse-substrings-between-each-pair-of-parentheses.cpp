class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        
        vector<int> op,cl;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                op.push_back(i);
            }
            if(s[i]==')')
            {
                reverse(s.begin()+op.back(),s.begin()+i);
                op.pop_back();
            }
        }
        
        
        string res="";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!='(' && s[i]!=')')
            {
                res+=s[i];
            }
        }
        
        return res;
    }
};