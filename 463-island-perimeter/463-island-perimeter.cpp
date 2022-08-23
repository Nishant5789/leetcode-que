class Solution {
    
    int check(int a, int b, int c, int d)
    {
        int count=0;
        if(a==1) count++;
        if(b==1) count++;
        if(c==1) count++;
        if(d==1) count++;
        
        return count;
     }
    int dfstraval(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return 1;
        
        if(grid[i][j]==2)
            return 0;
        
        grid[i][j]=2;
        int left = dfstraval(grid, i, j-1);
        int right = dfstraval(grid, i, j+1);
        int top = dfstraval(grid, i-1, j);
        int bottom = dfstraval(grid, i+1, j);

        return left+right+top+bottom;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(), count;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                   count = dfstraval(grid, i, j);
                }
            }
        }
        return count;
    }
};