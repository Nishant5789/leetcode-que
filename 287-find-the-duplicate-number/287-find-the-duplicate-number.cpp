class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> num;
        for(int i=0; i<nums.size(); i++)
        {
            if(num.count(nums[i])==0)
                num.insert(nums[i]);
            else
                return nums[i];
        }
        return 0;
    }
};