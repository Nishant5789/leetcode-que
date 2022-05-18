// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    
    int minNumber(int a[], int l, int h)
    {
        if(h < l) return -1;
        
        int ans = min(a[l],a[h]);
        while(h-l>1) {
            int mid = (l+h)/2;
            
            if(a[mid] > a[0]) {
                l = mid+1;
                ans = min(ans, a[l]);
            }
            else {
                h = mid;
                ans = min(ans, a[h]);
            }
        }
        return ans;
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends