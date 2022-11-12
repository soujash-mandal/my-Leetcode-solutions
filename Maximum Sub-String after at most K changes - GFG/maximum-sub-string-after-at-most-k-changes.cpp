//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		  //  vector<int> a(26,0);
		    
		    int n=s.size();
		    
		    int res=0;
		    
		    for(int j=0;j<26;j++)
		    {
		        int c=0;
		        int start=0;
		        for(int i=0;i<n;i++)
    		    {
    		        if(s[i]-'A'==j) c++;
    		        
    		        
    		        if(c+k>=(i-start+1))
    	            {
    	                res=max(res,i-start+1);
    	            }
    	            else
    	            {
    	                if(s[start]-'A'==j) c--;
    	                start++;
    	            }
    		        
    		    }
		    }
		    
		    
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends