class Solution {
    bool isvalid(int i, int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    void bfs(queue<pair<int,int>> q, int n, int m, vector<vector<char>> &ans, vector<vector<char>> &board)
    {
        vector<pair<int,int>> movements = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            auto v=q.front();
            q.pop();
            int v_x = v.first, v_y=v.second;
            ans[v_x][v_y]='O';
            for(auto movement: movements)
            {
                int child_x=v_x+movement.first, child_y=v_y+movement.second;
                if(!isvalid(child_x, child_y,n,m)) continue;
                if(board[child_x][child_y]!='O' || ans[child_x][child_y]!='X') continue;
                
                q.push({child_x,child_y});
                ans[child_x][child_y]='O';
            }
        }
    }
public:
    
    void solve(vector<vector<char>>& board) 
    {
        int n=board.size(), m=board[0].size(); 
        vector<vector<char>> ans(n, vector<char> (m,'X'));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            if(board[i][0]=='O')
                q.push({i,0});
            if(board[i][m-1]=='O')
                q.push({i,m-1});

        }
        for(int i=0; i<m ;i++)
        {
            if(board[0][i]=='O')
                q.push({0,i});
            if(board[n-1][i]=='O')
                q.push({n-1,i});
        }
        
        bfs(q, n, m, ans, board);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                board[i][j]=ans[i][j];
        }
    }
};