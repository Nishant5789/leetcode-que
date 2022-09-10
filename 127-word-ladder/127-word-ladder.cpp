class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> ans;
        for(auto i: wordList)
        {
            ans.insert(i);
        }
        int level=0;
        
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            int n=q.size();
            level++;
            while(n--)
            {
                string str=q.front();
                q.pop();
                
                if(endWord==str) 
                {
                    return level;
                }
                
                for(int i=0; i<str.length(); i++)
                {
                    char ch=str[i];
                    for(char c='a';c<='z';c++)
                    {
                        if(ch!=c)
                        {
                            str[i]=c;
                            if(ans.count(str)==1)
                            {
                                cout<<str<<" ";
                               q.push(str);
                                ans.erase(str);
                            
                            } 
                        }
                    }
                    str[i]=ch;
                }
            }
        }
        return 0;            
    }
};