class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0 || nums.size()==1)
        {
            return;
        }
        if(k>nums.size())
        k=k%nums.size();
        int n=nums.size()-k;
        vector<int> temp1(nums.begin()+n,nums.end());
        vector<int> temp2;
        for(int i=0; i<n; i++)
        {
            temp2.push_back(nums[i]);
        }
        int j=0;
        for(auto &i: temp1)
           nums[j++]=i;
        for(auto &i: temp2)
            nums[j++]=i;
    }
};