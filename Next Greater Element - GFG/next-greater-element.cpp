// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long>s;
        s.push(-1);
        vector<long long> num(n);
        long long curr, flag=0;
        for(int i=n-1; i>=0; i--)
        {
            curr=arr[i];
            if(s.top()!=-1)
            {
                while(curr >= s.top()) 
                {
                    s.pop();
                    if(s.top()==-1)
                    {
                        flag++;
                        break;
                    }
                }
            }
            else
            {
                flag++;
            }
            if(flag)
            {
                num[i]=-1;
                flag=0;
            }
            else
            {
                num[i]=s.top();
            }
            s.push(curr);
        } 
        return num;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends