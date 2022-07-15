// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& num, int n) 
    {
        // code here 
        stack<int> st;
        int m=num[0].size(),flag=0;
        for(int i=0; i<n; i++)
        {
            st.push(i);
        }
        while(st.size()>1)
        {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            
            if(num[op1][op2])
                st.push(op2);
            else
                st.push(op1);
            if(st.size()==0)
            {
                return -1;
            }
        }
        if(st.size()==1)
        {
            int x=st.top();
            for(int i=0; i<n; i++)
            {
                if(num[x][i]==1)
                {
                    st.pop();
                    st.push(-1);
                    break;
                }
                if(num[i][x]==0 && x!=i)
                {
                    st.pop();
                    st.push(-1);
                    break;
                }
            }
        }
        return st.top();
    }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends