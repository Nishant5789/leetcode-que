
class Solution {
public:
    int longestValidParentheses(string str) {
      int open=0, close=0, maxi=0;
      for(int i=0; i<str.size(); i++)
      {
            if(str[i]=='(')
                open++;
            else
                close++;
          if(open==close)
          {
            int l=open*2;
            maxi=max(maxi,l);
          }
          else
              if(close>open)
          {
              close=0;open=0;
          }
      }
      close=0;open=0;
      for(int i=str.size()-1; i>=0; i--)
      {
            if(str[i]==')')
                open++;
            else
                close++;
          if(open==close)
          {
            int l=open*2;
            maxi=max(maxi,l);
          }
          else
              if(close>open)
          {
              close=0;open=0;
          }
      }
        return maxi;
    }
};