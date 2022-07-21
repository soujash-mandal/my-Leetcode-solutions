class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> v(n,0);
        
        map<int,int> mp;
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            if(mp[arr[i]-d]!=0) 
            {
                int idx=mp[arr[i]-d];
                idx--;
                
                v[i]=max(v[i],v[idx]+1);
                res=max(res,v[i]);
            }
            
            mp[arr[i]]=i+1;
        }
        
        return res+1;
    }
};