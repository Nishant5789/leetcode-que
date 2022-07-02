class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int size=nums.size();
        int no_subset=1<<size;
        
        vector<vector<int>> powerset;
        set<vector<int>> flag;
        
        for(int i=0; i<no_subset; i++)
        {
            vector<int> set;
            for(int j=0; j<size; j++)
            {
                if((i&(1<<j)) != 0)
                {
                    set.push_back(nums[j]);
                }
            }
            sort(set.begin(),set.end());
            powerset.push_back(set);
        }
        for(auto &i:powerset)
        {
            flag.insert(i);
        }
        vector<vector<int>> powerset1;
        for(auto &i:flag)
        {
            powerset1.push_back(i);
        }
        return powerset1;
    }
};