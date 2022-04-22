class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> v(n, 0);
        int st = 0, end = n - 1, i = n - 1;
        while(i >= 0)
        {
            if(nums[st] * nums[st] > nums[end] * nums[end])
            {
                v[i--] = nums[st] * nums[st];
                st++;
            }
            else
            {
                v[i--] = nums[end] * nums[end];
                end--;
            }
        }
    return v;
    }
};