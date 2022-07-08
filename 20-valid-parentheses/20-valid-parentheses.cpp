class Solution {
public:
    bool isValid(string s) {
        stack<int> temp;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                temp.push(s[i]);
            }
            else
            {
                if(!temp.empty())
                {
                    if(s[i]==')' && temp.top()=='(' ||
                       s[i]=='}' && temp.top()=='{' ||
                       s[i]==']' && temp.top()=='[')
                            temp.pop();
                        else
                            return false;
                }
                else
                    return false;
            }
        }
        if(!temp.empty())
        {
            return false;
        }
        return true;
    }
};