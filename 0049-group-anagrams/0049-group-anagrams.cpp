class Solution {
public:
    struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<int>> ans;
        int l=strs.size();
        for(int i=0; i<l; i++)
        {
            string temp=strs[i];
            sort(temp.begin(), temp.end());
            ans[temp].push_back(i);
        }
        vector<vector<string>> result;
        for(auto &i: ans)
        {
            vector<string> temp;
            for(auto j: i.second)
            {
                temp.push_back(strs[j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};