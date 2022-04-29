// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int v[], int n, int x)
    {
    
    int j, l = n - 1;
    vector<int> num(v, v + n);
    sort(num.begin(), num.end());
    for(int i = 0; i < n - 2; i++)
    {
        j = i + 1;
        l = n - 1;
        while(j < l)
        {
            if(num[i] + num[j] + num[l] == x)
            {
                return 1;
                break;
            }
            else
                if(num[i] + num[j] + num[l] < x)
            {
                j++;
            }
            else
            {
                l--;
            }
        }
    }
    return 0;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends