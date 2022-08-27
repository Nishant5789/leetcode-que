class Solution {
    bool isvalid(int i, int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n=maze.size(), m=maze[0].size(), x = entrance[0], y=entrance[1];
        queue<pair<int,int>> q;
        vector<vector<int>> level(n, vector<int> (m,-1));

        for(int i=0; i<n; i++)
        {
            if(maze[i][0]=='.' && !(i==x && 0==y))
            {
                 q.push({i,0});
                 level[i][0]=0;
                 maze[i][0]='1';
            }
            if(maze[i][m-1]=='.' && !(i==x && m-1==y))
            {
                q.push({i,m-1});
                 level[i][m-1]=0;
                 maze[i][m-1]='1';
            }
        }
        for(int i=0; i<m; i++)
        {
            if(maze[0][i]=='.' && !(0==x && i==y))
            {
                q.push({0,i});
                 level[0][i]=0;
                 maze[0][i]='1';
            }
            if(maze[n-1][i]=='.' && !(n-1==x && i==y))
            {
                q.push({n-1,i});
                 level[n-1][i]=0;
                 maze[n-1][i]='1';
            }
        }
        
        vector<pair<int,int>> movements = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            auto v=q.front();
            q.pop();
            int v_x = v.first, v_y=v.second;
            
            for(auto movement: movements)
            {
                int child_x=v_x+movement.first, child_y=v_y+movement.second;
                if(!isvalid(child_x, child_y,n,m)) continue;
                if(maze[child_x][child_y]!='.') continue;
                
                q.push({child_x,child_y});
                maze[child_x][child_y]='1';
                level[child_x][child_y]=level[v_x][v_y]+1;
            }
        }
        return level[entrance[0]][entrance[1]];
    }
};