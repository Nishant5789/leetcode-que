// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    void reverse(stack<int>& St,int count,int size,vector<int>& num)
    {
        if(count==size)
        {
            return;
        }
        int n=St.top();
        num.push_back(n);
        St.pop();
        reverse(St, count+1, size, num);
        
    }
public:
    vector<int> Reverse(stack<int> St){
        int count=0, size=St.size();
        vector<int> num;
        reverse(St, count, size, num);
        return num;
        
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends