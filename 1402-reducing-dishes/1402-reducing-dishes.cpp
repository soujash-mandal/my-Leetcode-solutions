class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        
        sort(sat.begin(),sat.end(),greater<int>());
        
        int res=0;
        int sum=0;
        int currsum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=currsum+sat[i];
            currsum+=sat[i];
            res=max(res,sum);
        }
        
        return res;
    }
};