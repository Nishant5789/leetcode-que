class Solution
{
public:
    void replace(int i, int j, int &m, int &n, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1)
            return;
        
        grid[i][j] = 1;
        replace(i - 1, j, m, n, grid);
        replace(i, j - 1, m, n, grid);
        replace(i + 1, j, m, n, grid);
        replace(i, j + 1, m, n, grid);
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int i, j;
        // first convert all the boundary land(0)  and their adjacent cell into water(1) 
        for (i = 0; i < n; i++)
        {
            if (grid[0][i] == 0)
            {
                replace(0, i, m, n, grid);
            }
            if (grid[m - 1][i] == 0)
            {
                replace(m - 1, i, m, n, grid);
            }
        }
        for (i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                replace(i, 0, m, n, grid);
            }
            if (grid[i][n - 1] == 0)
            {
                replace(i, n - 1, m, n, grid);
            }
        }
        int ans = 0;
        // if any grid found 0 then it ans because it not reached to boundary
        for (i = 1; i < m - 1; i++)
        {
            for (j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 0)
                {
                    ans++;
                    replace(i, j, m, n, grid);
                }
            }
        }
        return ans;
    }
};