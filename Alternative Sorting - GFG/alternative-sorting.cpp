// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	vector<int> alternateSort(int ar[], int n)
	{
	    vector<int> arr(ar, ar+n);
        sort(arr.begin(), arr.end(),greater<int>());
        int j=0;
        vector<int> num(n);
        for(int i = 0; i < n/2; i++)
        {
            num[j++] = arr[i];
            num[j++] = arr[n-i-1];
        }
        if(n & 1)
        num[j++] = arr[(n/2)];
        return num;
        
	}

};
	

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
       

        Solution ob;
        vector<int> ans = ob.alternateSort(a, n);
        for(auto i:ans)
        	cout << i << " ";
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends