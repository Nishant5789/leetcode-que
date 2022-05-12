// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
    unordered_map<int, int> num;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        num[a[i]]++;
    }
    unordered_set<int> num2;
    for(int i = 0; i < m; i++)
    {
        if(num.count(b[i]) && num2.count(b[i]) == 0)
        {
                count++;
        }
        num2.insert(b[i]);
    }
    return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends