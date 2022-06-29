
bool fun(map<char, int> hash1,set<char> hash2)
{
    for(auto &i: hash2)
    {
        if(hash1[i]!=0)
            return 0;     
    }
    return 1;
}

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> hash1;
        set<char> hash2;
        for(int i=0; i<s.size(); i++)
        {
            hash1[s[i]]++;
        }
        vector<int> temp;
        int pre=0;
        for(int i=0; i<s.size(); i++)
        {
            hash2.insert(s[i]);
            hash1[s[i]]--;
            if(fun(hash1,hash2))
            {
                temp.push_back(i+1-pre);
                pre=i+1;
                hash2.clear();
            }
        }
        return temp; 
    }
};