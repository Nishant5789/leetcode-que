// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution
{   
    public:
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        set<int> s;

        for (int i=0; i<matrix.size(); i++) {
            bool found=false;
            
            for (int j=0; j<matrix[i].size(); j++) {
                // Keep adding column indexes in the set, whenever we see a '1'
                if (matrix[i][j]==1) {
                    s.insert(j);
                    found=true;
                }
            }
    
            // If there is atleast one '1', then create a new row with all '1' and assign it to the current row.
            if (found) {
                vector<int> row(matrix[i].size(), 1);
                matrix[i]=row;
            }
        }
    
        /** 
         * Till this point we have taken care of only the row.
         * To handle columns, we itertate over the set, for each column index in the set, fill the entire column with '1'.
         * */
        for (int i : s) {
            for (int j=0; j<matrix.size(); j++) {
                matrix[j][i]=1;
            }
        }
}
    
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}


  // } Driver Code Ends