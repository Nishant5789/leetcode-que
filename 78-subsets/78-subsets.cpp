class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int size=nums.size();
        int num_subset=1<<size;
        vector<vector<int>> powerset;
        for(int submask=0; submask<num_subset; submask++)
        {
            vector<int> set;
            for(int i=0; i<size; i++)
            {
                if((submask&(1<<i))!=0)
                {
                    set.push_back(nums[i]);
                }
            }
            powerset.push_back(set);
        }
        return powerset;
    }
};