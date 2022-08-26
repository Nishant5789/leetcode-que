class Solution {   
    bool isvalid(int i, int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> ans(n, vector<int> (m,0)),level(n, vector<int> (m,0));
        int count=0;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    level[i][j]=0;
                    mat[i][j]=2;
                    count++;
                }
            }
        }
        if(count==n*m)
            return level;
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
                if(mat[child_x][child_y]!=1) continue;
                
                q.push({child_x,child_y});
                mat[child_x][child_y]=2;
                level[child_x][child_y]=level[v_x][v_y]+1;
            }
        }
        return level;
    }
};