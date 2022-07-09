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
                // adding number of open bracket
                add++;
            }
            else
            {
                if(!st.empty())
                {
                    if('('==st.top())
                    {
                        add--;
                        // balance the brackets
                    }
                    st.pop();
                }
                else
                {
                     //for closed bracets count that appear before the open brackets
                    add++;
                }
            }
        }
        return add;
    }
};