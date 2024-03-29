class Solution {
    
    void dfs(int i, int j, vector<vector<int>> &grid, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1)
            return ;
        
        grid[i][j]=2;
        
        vector<pair<int,int>> movements ={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto movement: movements)
        {
            dfs(i+movement.first, j+movement.second, grid, n, m);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==1)
            {
                dfs(i,0, grid, n, m);
            }
             if(grid[i][m-1]==1)
            {
                dfs(i,m-1, grid, n, m);
            }
        }
        for(int i=0; i<m; i++)
        {
            if(grid[0][i]==1)
            {
                dfs(0,i, grid, n, m);
            }
            if(grid[n-1][i]==1)
            {
                dfs(n-1,i, grid, n, m);
            }
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};