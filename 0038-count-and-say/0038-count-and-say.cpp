class Solution {
public:
    string countAndSay(int n1) {
        if(n1==1)
            return "1";
        if(n1==2)
            return "11";
        string str=countAndSay(n1-1);
        string ans="";
        int n=str.size();
        int count=1;
        for(int i=0;i<n-1;i++)
        {
            if(str[i]==str[i+1])
            {
                count++;
            }
            else
            {
                string temp=to_string(count);
                ans+=temp;
                ans+=str[i];
                count=1;
            }
        }
        
        if(str[n-1]!=str[n-2])
        {
            ans+="1";
            ans+=str[n-1];
        }
        if(str[n-1]==str[n-2])
        {
            ans+=to_string(count);
            ans+=str[n-1];
        }
        
        
        return ans;
        
    }
};