class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(370,0);
        
        int n=days.size();
        
        for(int i=0;i<n;i++)
        {
            dp[days[i]]++;
        }
        
        
        for(int i=1;i<=365;i++)
        {
            int a;
            if(dp[i]) a=dp[i-1]+costs[0];  
            else a=dp[i-1];
            
                dp[i]=a;
                
                int ib=max(i-7,0);
                int b=dp[ib]+costs[1];

                dp[i]=min(dp[i],b);

                int ic=max(i-30,0);
                int c=dp[ic]+costs[2];

                dp[i]=min(dp[i],c);
                
            
            
        }
        return dp[365];
        
    }
};