class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int res=0;
        
        int dp[m][n];
        
        for(int i=0;i<m;i++)
        {
            if(nums1[i]==nums2[0])
            {
                dp[i][0]=1;
                res=1;
            }
            else
                dp[i][0]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(nums2[i]==nums1[0])
            {
                res=1;
                dp[0][i]=1;
            }
            else
                dp[0][i]=0;
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        
        return res;
    }
};