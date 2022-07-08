class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(), l2=nums2.size(), temp=0, i=0,j=0;
        int n=l1+l2;
        vector<int> num(n);
        while(i<l1 && j<l2)
        {
            if(nums1[i]<nums2[j])
            {
                num[temp++]=nums1[i++];
            }
            else
            {
                num[temp++]=nums2[j++];
            }
        }
        while(i<l1)
        {
             num[temp++]=nums1[i++];
        }
        while(j<l2)
        {
            num[temp++]=nums2[j++];
        }
        if(n&1)
        {
            return (double)num[(n+1)/2-1];
        }
        else
        {
            return(double)(num[(n/2)-1]+num[(n/2)])/2;
        }
    }
};