// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    vector<int> nextsmaller(int arr[], int n)
    {
        stack<int> s;
        s.push(-1);
        int curr;
        vector<int> num(n);
        for(int i=n-1; i>=0; i--)
        {
            curr=arr[i];
            // most crucial codition that check tha stack is not empty for both the cases
            while(s.top() != -1 && arr[s.top()] >= curr) 
            {
                s.pop();
            }   
            num[i]=s.top();
            s.push(i);
        } 
        return num;
    }
    vector<int> prevsmaller(int arr[], int n)
    {
        stack<int> s;
        s.push(-1);
        int curr;
        vector<int> num(n);
        for(int i=0; i<n; i++)
        {
            curr=arr[i];
            // most crucial codition that check tha stack is not empty for bth the cases
            while(s.top()!=-1 && curr<=arr[s.top()]) 
            {
                s.pop();
            }   
            num[i]=s.top();
            s.push(i);
        } 
        return num;
    }
    int largestRectangleArea(int heights[], int n) {
        // int n=heights.size();
        
        vector<int> next(n);
        vector<int> prev(n);
        
        //FIRST CALL THE FUNTION TO FIND THE next small & next previous element for findi the min-width
        // same as the small element que
        next = nextsmaller(heights, n);
        prev = prevsmaller(heights, n);
        int maxarea;
        for(int i=0; i<n; i++)
        {
            int l=heights[i];
            // if the the rectangle touch the last element so height[last index] is always -1 so we change it through n;
            if(next[i]==-1)
            {
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int area=INT_MIN;
            area=l*b;
            maxarea=max(area,maxarea);
        }
        return maxarea; 
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int area = largestRectangleArea(M[0], m);
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // add the uper row in current row
                if(M[i][j]!=0)
                    M[i][j]=M[i][j] + M[i-1][j];
                else
                    M[i][j]=0;
            }
            // entire row is updated
            area=max(area,largestRectangleArea(M[i], m));
        }
        return area;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends