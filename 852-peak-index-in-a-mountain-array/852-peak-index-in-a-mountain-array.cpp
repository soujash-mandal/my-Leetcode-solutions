class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        
        int l=1;
        int r=n-2;
        
        while(r>=l)
        {
            int mid=l+(r-l)/2;
            
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
            
            if(arr[mid]>arr[mid-1]) l=mid+1;
            else r=mid-1;
            
        }
        
        return -1;
    }
};