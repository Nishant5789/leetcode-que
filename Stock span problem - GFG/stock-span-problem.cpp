// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>  prevgreater(n);
        stack<int> s;
        for(int i=n-1; i>=0; i--)
        {
            while(s.size()!=0 && price[s.top()]<price[i])
            {
                prevgreater[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(s.size()!=0)
            {
                prevgreater[s.top()]=-1;
                s.pop();
            }
        for(int i=0; i<n; i++)
        {
            if(prevgreater[i]!=-1)
                prevgreater[i]=i-prevgreater[i];
            else
                 prevgreater[i]=i+1;
        }
        return prevgreater;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends