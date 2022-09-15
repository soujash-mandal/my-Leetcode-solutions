class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        int n=arr.size();
        vector<int> res;
        map<int,int> m;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(m[arr[i]])
            {
                m[arr[i]]--;
                if(m[arr[i]*2]<=0)
                {
                    return {};
                }
                res.push_back(arr[i]);
                m[arr[i]*2]--;
            }
        }
        
        return res;
    }
};