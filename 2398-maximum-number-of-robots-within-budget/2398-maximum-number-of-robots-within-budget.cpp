class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n=chargeTimes.size();
        int ans=0;
        
        
        set<int> s;
        s.insert(0);
        map<int,int> mp;
        int cost=0;
        int k=0;
        
        
        
        long long sum_rc=0;
        int start_idx=0;
        
        for(int i=0;i<n;i++)
        {
            k++;
            sum_rc+=runningCosts[i];
            mp[chargeTimes[i]]++;
            s.insert(chargeTimes[i]);
             
            
            
            auto iterator=s.end();
            iterator--;
            long long total=*iterator+k*1LL*sum_rc;
            
            while(total>budget)
            {
                k--;
                sum_rc-=runningCosts[start_idx];
                mp[chargeTimes[start_idx]]--;
                if(mp[chargeTimes[start_idx]]==0) s.erase(chargeTimes[start_idx]);
                
                auto it=s.end();
                it--;
                total=*it+sum_rc*1LL*k;
                start_idx++;
            }
            
            
            ans=max(k,ans);
        }
        
        return ans;
    }
};