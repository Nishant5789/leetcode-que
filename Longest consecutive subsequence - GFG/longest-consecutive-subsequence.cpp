// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        map<int, int> num;
        for(int i = 0;i < N; i++)
        {
            num[arr[i]]++;
        }
        auto i1 = num.begin();
        auto i2 = ++i1;i1--;
        int i = 0, j = -1, length = 1;
        while(i < N)
        {
            if(i1->first + 1 != i2->first)
            {
                length = max(length,abs(j - i));
                i1++;i2++;i++;
                j = i - 1;
            }
            else
                {
                    i1++;i2++;i++;
                }
            
        }
        return length;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends