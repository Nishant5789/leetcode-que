class Solution {
    
    bool isvalid(int i, int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> level(n, vector<int> (n,-1));
        if(grid[0][0]==1)
            return -1;
        
       queue<pair<int,int>> q;
        q.push({0,0});
        level[0][0]=0;
        grid[0][0]=1;
        vector<pair<int,int>> movements ={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    
        while(!q.empty())
        {
             auto v = q.front();
             q.pop();
             int v_x = v.first;
             int v_y = v.second;
            
            // cout << v_x << " "<< v_y << endl;
             
             for(auto movement: movements)
             {
                int child_x = movement.first + v_x;
                int child_y = movement.second + v_y;
                 
                if(!isvalid(child_x,child_y, n, m)) continue;
                if(grid[child_x][child_y]==1) continue;
                 
                q.push({child_x, child_y});
                grid[child_x][child_y]=1;
                level[child_x][child_y]=level[v_x][v_y]+1;
             }
        }   
        return (level[n-1][m-1]==-1)? -1:level[n-1][m-1]+1;
    }
};