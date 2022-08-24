class Solution {
    bool isvalid(int i, int j,int n,int m, vector<vector<int>> grid){
        return i>=0 && j>=0 && i<n && j<m && grid[i][j]!=0;
    }
    int bfs(vector<vector<int>> grid,vector<vector<int>> visited,vector<vector<int>> level, int n, int m, int count)
    {
        queue<pair<int,int>> q;
        int two=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(2==grid[i][j])
                {
                    q.push({i,j});
                    level[i][j]=0;
                    visited[i][j]=1;
                    two++;
                }
            }
        }
        vector<pair<int,int>> movements ={{1,0},{0,1},{-1,0},{0,-1}};
        int ans=0;
        if(!q.empty())
        count += two;
        while(!q.empty())
        {
             auto v = q.front();
             q.pop();
             count--;
             int v_x = v.first;
             int v_y = v.second;
             
             for(auto movement: movements)
             {
                int child_x = movement.first + v_x;
                int child_y = movement.second + v_y;
                 
                if(!isvalid(child_x,child_y, n, m, grid)) continue;
                if(visited[child_x][child_y]) continue;
                 
                q.push({child_x, child_y});
                level[child_x][child_y] = level[v_x][v_y]+1;
                visited[child_x][child_y]=1;
                ans=max(ans, level[child_x][child_y]);
             }
        }
        // cout << count << "ans-";
        return (count==0)?ans:-1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size(), m=grid[0].size(), count=0;
        vector<vector<int>> level, visited;
        
        
        for(int i=0; i<n; i++)
        {
            vector<int> temp1, temp2;
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1) count++;
                temp1.push_back(0);
                temp2.push_back(INT_MAX);
            }
            visited.push_back(temp1);
            level.push_back(temp2);
        }
        return bfs(grid, visited, level, n, m, count);
    }
};