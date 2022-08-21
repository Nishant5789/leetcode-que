class Solution { 
    int maxi(vector<int> &x, vector<int> &y, vector<int> &z)
    {
        return max(row_max(x),max(row_max(y),row_max(z)));
    }
    int row_max(vector<int> num)
    {
        // cout << num[0] << " " << num[1] << " " << num[2]<< endl;
        return max(num[0],max(num[1],num[2]));
    }
    void set_max(vector<int> &temp, vector<vector<int>> &grid, int i, int j)
    {
        // cout << grid[i][j] << " ";
        temp.push_back(grid[i][j++]);
         // cout << grid[i][j] << " ";
        temp.push_back(grid[i][j++]);
         // cout << grid[i][j] << " ";
        temp.push_back(grid[i][j++]);
        // cout << endl;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> arr;
        for(int i=0; i<n-2; i++)
        {
            vector<int> temp;
            for(int j=0; j<n-2; j++)
            {
                 vector<int> temp1, temp2, temp3;
                 set_max(temp1, grid, i, j);
                 set_max(temp2, grid, i+1, j);
                 set_max(temp3, grid, i+2, j);
                 temp.push_back(maxi(temp1,temp2, temp3));
            }
            arr.push_back(temp);
        }
        return arr;
    }
};