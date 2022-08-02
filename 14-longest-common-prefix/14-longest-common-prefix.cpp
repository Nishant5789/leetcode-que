class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
              string ans="";
    int min_len=201;
    int n=strs.size();
    for(int i=0;i<n;i++)
    {
        if(strs[i].length()<min_len)
            min_len=strs[i].length();
    }
    
    int x=0;
    while(x<min_len)
    {
        string s=strs[0];
        char ch=s[x];
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            string j=strs[i];
            if(j[x]==ch)
                cnt++;
        }
        if(cnt==n)
            ans.push_back(ch);
        else
            break;
        x++;
    }
    return ans;
    
}

};