class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> num;
        for(auto &i: nums)
        {
           num[i]++;
        }
        for(auto &i: num)
        {
           
            if(i.second>1)
            {
                return 1;
                break;
            }
        }
        return 0;
    }
};