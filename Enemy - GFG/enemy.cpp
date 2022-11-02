//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &e)
        {
            vector<int> col,row;
            col.push_back(-1);
            col.push_back(m);
            
            row.push_back(-1);
            row.push_back(n);
            
            for(int i=0;i<k;i++)
            {
                col.push_back(e[i][1]-1);
                row.push_back(e[i][0]-1);
            }
            
            sort(col.begin(),col.end());sort(row.begin(),row.end());
            
            int mxr=0,mxc=0;
            
            for(int i=1;i<row.size();i++)
            {
                mxr=max(mxr,row[i]-row[i-1]-1);
                mxc=max(mxc,col[i]-col[i-1]-1);
            }
            return mxr*mxc;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends