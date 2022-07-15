class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        stack<int> st;
        int n=temp.size();
        vector<int> num(n);
        for(int i=0; i<n; i++)
        {
            while(st.size()!=0 && temp[st.top()]<temp[i])
            {
                num[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()!=0)
        {
            num[st.top()]=-1;
            st.pop();
        }
        for(int i=0; i<n; i++)
        {
            if(num[i]!=-1)
                temp[i]=num[i]-i;
            else
                temp[i]=0;
        }
        return temp;
    }
};