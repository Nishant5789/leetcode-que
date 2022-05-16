// { Driver Code Starts
//Initial Template for C

#include <stdio.h> 


 // } Driver Code Ends
//User function Template for C

int searchInSorted(int arr[], int N, int K) 
{ 
    
    int l=0, h=N-1,mid;
    while(h-l>1)
    {
        mid=(h+l)/2;
            if(arr[mid]<K)
            {
                l=mid+1;
            }
        else
        {
            h=mid;
        }
    }
    if(arr[l]==K || arr[h]==K)
    return 1;
    else
    return -1;
}

// { Driver Code Starts.


int main(void) 
{ 
    
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d%d", &n, &k);
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        
        printf("%d\n", searchInSorted(arr, n, k));

    }

	return 0; 
} 
  // } Driver Code Ends