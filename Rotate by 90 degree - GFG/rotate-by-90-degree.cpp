// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& a)
{
    vector<vector<int>> num;
    int n = a.size();
    for(int i=0; i<n; i++)
    {
        vector<int> temp(n);
        num.push_back(temp);
        for(int j=0; j<n; j++)
        {
            num[i][j] = a[j][n-i-1];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j] = num[i][j];
        }
    }
    
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends