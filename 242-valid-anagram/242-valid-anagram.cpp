class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> str1(123, 0), str2(123, 0);
        for(auto &i: s)
        {
            str1[i]++;
        }
        for(auto &i: t)
        {
            str2[i]++;
        }
        if(str1 == str2)
            return true;
        else
            return false;
        
    }
};