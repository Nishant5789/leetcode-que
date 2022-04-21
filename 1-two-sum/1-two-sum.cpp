class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <pair<int,int>> v1;
        vector <int> v;
        int index = 0;
        for(auto i : nums)
        {
            v1.push_back(make_pair(i, index++));
        }
        sort(nums.begin(), nums.end());
        int i = 0, j;
        j = nums.size() - 1;
        while(nums[i] + nums[j] != target)
        {
            if(nums[i] + nums[j] < target)
                i++;
            else
                j--;
        }
        for(auto it : v1)
        {
            if(it.first == nums[i] || it.first == nums[j])
                v.push_back(it.second);  
        }
        return v;
        
    }
};