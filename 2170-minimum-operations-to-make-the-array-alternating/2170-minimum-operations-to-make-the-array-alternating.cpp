class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        
        map<int,int> mp1,mp2;
        
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                mp1[nums[i]]++;
            }
            else
            {
                mp2[nums[i]]++;
            }
        }
        
        vector<vector<int>> v1,v2;
        for(auto it:mp1)
        {
            v1.push_back({it.second,it.first});
        }
        for(auto it:mp2)
        {
            v2.push_back({it.second,it.first});
        }
        
        sort(v1.begin(),v1.end(),greater<vector<int>>());
        sort(v2.begin(),v2.end(),greater<vector<int>>());
        
        v1.push_back({0,0});
        v2.push_back({0,0});
        
        if(v1[0][1]!=v2[0][1]) return n-(v1[0][0]+v2[0][0]);
        else
        {
            int a=n-(v1[0][0]+v2[1][0]);
            int b=n-(v1[1][0]+v2[0][0]);
            
            return min(a,b);
        }
        
    }
};