class Solution {
public:
    int findElelement(vector<int>& nums1, vector<int>& nums2,int x)
    {
        int n1=nums1.size();
        int n2=nums2.size();
        // median in nums1 case
            int l1=0;
            int r1=n1-1;
            
            while(r1>=l1)
            {
                int mid=(l1+r1)/2;
                
                int idxlo=lower_bound(nums2.begin(),nums2.end(),nums1[mid])-nums2.begin();
                int idxhi=upper_bound(nums2.begin(),nums2.end(),nums1[mid])-nums2.begin();
                
                // if(mid+idxlo==x) return nums1[mid];
                
                 if(mid+idxlo>x) 
                 {
                     r1=mid-1;
                 }
                else if(mid+idxhi<x)
                {
                    l1=mid+1;
                }
                else
                {
                    return nums1[mid];
                }
                  
            } 
        
            // median in nums2 case
            
            l1=0;
            r1=n2-1;
            
            
            while(r1>=l1)
            {
                int mid=(l1+r1)/2;
                
                int idxlo=lower_bound(nums1.begin(),nums1.end(),nums2[mid])-nums1.begin();
                int idxhi=upper_bound(nums1.begin(),nums1.end(),nums2[mid])-nums1.begin();
                
                // if(mid+idxlo==x) return nums1[mid];
                
                 if(mid+idxlo>x) 
                 {
                     r1=mid-1;
                 }
                else if(mid+idxhi<x)
                {
                    l1=mid+1;
                }
                else
                {
                    return nums2[mid];
                }
                  
            }
        return 0;
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        
        int n1=nums1.size();
        int n2=nums2.size();
    
        
        if((n1+n2)%2)
        {
                return findElelement(nums1,nums2,(n1+n2)/2);
        }
        else
        {
            double a=findElelement(nums1,nums2,(n1+n2)/2);
            double b=findElelement(nums1,nums2,(n1+n2-1)/2);
            
            // cout<<a<<" "<<b<<endl;
            
            return (a+b)/2;
        }
        
        return 0;
    }
};