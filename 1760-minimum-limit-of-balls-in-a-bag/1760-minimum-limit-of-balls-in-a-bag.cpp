class Solution {
public:
    bool pred(vector<int>& nums,int mid,int maxOperations)
    {
        int n=nums.size();
        int op=0;
        for(int i=0;i<n;i++)
        {
            int x=nums[i]/mid;
            if(nums[i]%mid) x++;
            
            op+=x-1;
        }
        
        if(op<=maxOperations)return true;
        else return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int r=1e9;
        int res=r;
        
        while(r>=l)
        {
            int mid=l+(r-l)/2;
            if(pred(nums,mid,maxOperations))
            {
                // cout<<mid<<endl;
                res=mid;
                r=mid-1;
            }
            else
            {
                // cout<<"not"<<mid<<endl;
                l=mid+1;
            }
        }
        
        return res;
    }
};