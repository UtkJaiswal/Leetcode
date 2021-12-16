class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size(),m=nums2.size();
        int start=0,end=n;
        while(start<=end)
        {
            int px=(start+end)/2;
            int py=(n+m)/2-px;
            
            int l1=px==0?INT_MIN:nums1[px-1];
            int l2=py==0?INT_MIN:nums2[py-1];
            int r1=px==n?INT_MAX:nums1[px];
            int r2=py==m?INT_MAX:nums2[py];
            
            if(l1>r2)
                end=px-1;
            
            else if(l2>r1)
                start=px+1;
            
            else
                return (n+m)%2?min(r1,r2):(min(r1,r2)+max(l1,l2))/2.;
        }
        return 0;
    }
};