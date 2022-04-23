class Solution {
public:
    int strStr(string &str, string &s) {
        int index = -1, count, flag = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if(flag)break;
            count = 0;
            if(str[i] == s[0]){
                for(int j = 0; j < s.size(); j++)
                {
                    if(str[i + j] != s[j])
                        break;
                        count++;
                }
                if(count == s.size())
                {
                    index = i;
                    flag++;
                }
            }
        }
        return index;
        
    }
};