class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)q.push({i,j});
            }
        }
        if(q.size()==0 || q.size()==(n*m))return -1;
        int level=-1;
        while(!q.empty()){
            level++;
            int size = q.size();
            while(size>0){
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                int dx[]={-1,0,1,0};
                int dy[]={0,-1,0,1};

                for(int i=0;i<4;i++)
                {
                    int x=a+dx[i];
                    int y=b+dy[i];

                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0)
                    {
                        q.push({x,y});
                        grid[x][y]=1;
                    }
                }
                size--;
            }
        }
        return level;
    }
};