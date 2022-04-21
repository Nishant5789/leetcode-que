// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

int prime_no(int n)
{
    int k=sqrt(n);
    for(int i=2;i<=k;i++)
        if(n%i==0)
            return -1;
    return 1;
}


class Solution {
  public:
    vector<int> primeRange(int M, int N) {
          vector<int> v(0);
        if(M==1)
            M++;
        for(int i=M;i<=N;i++)
        {
            if(prime_no(i)==1)
                v.push_back(i);
        }
            return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends