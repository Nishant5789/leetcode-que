class Solution {
public:
    int partitionDisjoint(vector<int>& nums)
    {
        int n=nums.size();
        int part1=INT_MIN, part2=INT_MAX, ans=n-1;
        vector<int> maxi, mini;
        for(int i=0; i<nums.size(); i++)
        {
            part1=max(part1, nums[i]);
            // cout << part1 << " ";
            maxi.push_back(part1);
            part2=min(part2, nums[n-1-i]);
            // cout << part2 << " ";
            mini.push_back(part2);
        }
        reverse(mini.begin(), mini.end());

        for(int i=0; i<n-1; i++)
        {
            int j=i+1;
            if(maxi[i]<=mini[j])
            {
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};