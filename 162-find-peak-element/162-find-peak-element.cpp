class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size(), l=0, r=n-1;
        // here note that why we not use equals to sign because 
        while(l<r)
        {
            int mid=l+(r-l)/2;
            // why this approach here we have multiple option for which side we choose either left side or right side if we used only two condition
            // so we need to anaylysis something
            // we have four option d means decresing and i means incresing and middle index is mid formula for nibary search
            //(1)-III (2) ddd (3)idi (4) did
            // (1)(3) option we used l = mid + 1(why)
            // (2)(4) option we used l = mid + 1
            
            // if we find the peak element but we don't stop the loop because there multiple peak exits
            if(arr[mid] <= arr[mid+1])
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};