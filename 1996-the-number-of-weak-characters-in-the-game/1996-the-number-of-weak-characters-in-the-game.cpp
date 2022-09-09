class Solution {
public:
    static bool comp(vector<int>& v1,vector<int>& v2)
    {
        if(v1[0]<v2[0]) return true;
        if(v1[0]==v2[0]) return v1[1]>=v2[1];
        return false;
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        
        sort(p.begin(),p.end(),comp);
        
        stack<int> st;
        
        int n=p.size();
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            int x=p[i][1];
            
            if(st.size()==0)
            {
                st.push(x);
            }
            else if(x<st.top())
            {
                st.push(x);
            }
            else
            {
                while(st.size()>0 && st.top()<x)
                {
                    st.pop();
                    res++;
                }
                st.push(x);
            }
        }
        return res;
    }
};