class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size(), l=0, r=n-1;
        
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid] > arr[mid+1])
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};