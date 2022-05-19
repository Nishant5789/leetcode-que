class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, h=n-1,res=-1;
        if(nums[h] < target)  return n;
        else if(nums[l] > target)  return 0;
        while(h-l>1)
        {
            int mid=(l+h)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else
                if(nums[mid]>target)
                {
                    res=mid;
                    h=mid;
                }
            else{
                    l=mid;
            }
        }
        if(nums[l]==target)   res=l;
        else if(nums[h]>=target) res=h;
        return res;
    }
};