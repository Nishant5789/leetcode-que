class Solution {
    
    void dfstraval(vector<vector<char>> &grid, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return;
        
        if(grid[i][j]!='1')
            return;
        
        grid[i][j]='2';
        
        dfstraval(grid, i+1, j);
        dfstraval(grid, i-1, j);
        dfstraval(grid, i, j+1);
        dfstraval(grid, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size(), count=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfstraval(grid, i, j);
                }
            }
        }
        return count;
    }
};