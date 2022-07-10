class Solution {
    
    vector<int> nextsmaller(vector<int>& arr, int n)
    {
        stack<int> s;
        s.push(-1);
        int curr;
        vector<int> num(n);
        for(int i=n-1; i>=0; i--)
        {
            curr=arr[i];
               while(s.top() != -1 && arr[s.top()] >= curr) 
            {
                s.pop();
            }   
            num[i]=s.top();
            s.push(i);
        } 
        return num;
    }
    
    vector<int> prevsmaller(vector<int>& arr, int n)
    {
        stack<int> s;
        s.push(-1);
        int curr;
        vector<int> num(n);
        for(int i=0; i<n; i++)
        {
            curr=arr[i];
            while(s.top()!=-1 && curr<=arr[s.top()]) 
            {
                s.pop();
            }   
            num[i]=s.top();
            s.push(i);
        } 
        return num;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        vector<int> next(n);
        vector<int> prev(n);
        
        next = nextsmaller(heights, n);
        prev = prevsmaller(heights, n);
        int maxarea;
        for(int i=0; i<n; i++)
        {
            int l=heights[i];
            
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
};