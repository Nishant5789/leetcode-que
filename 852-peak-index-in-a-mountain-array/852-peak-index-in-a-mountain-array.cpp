class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size(), l=0, h=n-1, res=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
            {
                res=mid;
                break;
            }
            else 
                if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1])
            {
                l=mid;
            }
            else
            {
                h=mid;
            }
        }
        return res;
    }
};