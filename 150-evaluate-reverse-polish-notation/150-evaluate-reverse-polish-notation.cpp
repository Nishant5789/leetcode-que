#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
   stack<string> st;
        int ans = 0;
        int top1 = 0, top2 = 0;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+" and tokens[i]!="-" and tokens[i]!="*" and tokens[i]!="/" )
            {
                st.push(tokens[i]);
            }
            else
            {
                if(!st.empty()) top1 = stoi(st.top());
                st.pop();
                if(!st.empty()) top2 = stoi(st.top());
                st.pop();
                if(tokens[i]=="+")
                {
                    int num = top2 + top1;
                    // ans += num;
                    st.push(to_string(num));
                    // ans +=
                }
                else 
                    if(tokens[i]=="*")
                    {
                        int num = top2 * top1;
                        st.push(to_string(num));
                    }
                else
                    if(tokens[i]=="/") 
                    {
                        int num = top2/top1;
                        st.push(to_string(num));
                    }
                else 
                    if(tokens[i]=="-")
                    {
                        int num = top2 - top1;
                        st.push(to_string(num));
                    }
            }
        }
        while(!st.empty()) {
            ans = stoi(st.top());
            st.pop();
        }
        return ans;
    }
};