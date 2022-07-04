// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
        unordered_map<int,int> num;
        unordered_set<int> container;
        for(int i=0; i<n; i++)
        {
            if(container.count(arr[i])==0)
            {
                num[arr[i]]=i;
            }
        }
        container.clear();
        int maxi=INT_MIN;
        for(int i=n-1; i>=0; i--)
        {
            if(container.count(arr[i])==0)
            {
                maxi=max(maxi,abs(i-num[arr[i]]));
            }
        }
        return maxi;
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
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends