class Solution {
    int dfstraval(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return 0;
        
        if(grid[i][j]!=1)
            return 0;
        
        grid[i][j]=2;
        
        int right = dfstraval(grid, i+1, j);
        int left = dfstraval(grid, i-1, j);
        int top = dfstraval(grid, i, j+1);
        int bottom = dfstraval(grid, i, j-1);
        
        return right+top+bottom+left+1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(), maxi=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    maxi=max(maxi,dfstraval(grid, i, j));
                }
            }
        }
        return maxi;
    }
};