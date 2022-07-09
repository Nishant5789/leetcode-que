class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int  add=0, count=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                add++;
            }
            else
            {
                if(!st.empty())
                {
                    if('('==st.top())
                    {
                        add--;
                    }
                    st.pop();
                }
                else
                {
                    add++;
                }
            }
        }
        return add;
    }
};